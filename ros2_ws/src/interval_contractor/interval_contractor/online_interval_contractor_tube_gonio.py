import rclpy
from rclpy.node import Node
from codac import *
from interval_analysis_interfaces.msg import Interval as IntervalMsg
from interval_analysis_interfaces.msg import BoxStamped as BoxMsgStamped
from interval_analysis_interfaces.msg import BoxListStamped as BoxListStampedMsg
from std_msgs.msg import Header
from builtin_interfaces.msg import Time
import numpy as np
import codac as c1
import codac2 as c2
import interval_contractor.interface_codac as Interface
import math

class CtcMultiBearing(c2.Ctc):

  def __init__(self, m_, y_):
    c2.Ctc.__init__(self, 3)
    self.m = m_
    self.y = y_

  def contract(self, x):
    n = len(self.m)
    A = c2.IntervalMatrix(n,2)
    b = c2.IntervalVector(n)
    p = c2.IntervalVector([x[0],x[1]])
    
    for i in range(0,n):
      A[i,0] = c2.sin(x[2]+self.y[i])
      A[i,1] = -c2.cos(x[2]+self.y[i])
      b[i] = self.m[i][0]*c2.sin(x[2]+self.y[i])-self.m[i][1]*c2.cos(x[2]+self.y[i])
      
    c2.MulOp.bwd(b,A,p)
    x.put(0,p)
    return x

class Ctc_gonio(c1.Ctc):

  def __init__(self, M_, y_):
    c1.Ctc.__init__(self, 3) # the contractor acts on 3d boxes
    self.m = M_  # Store the landmarks
    self.y = y_  # Store the bearings    # attribute needed later on for the contraction
    self.M2, self.y2 = self.c1_to_c2()
    self.ctc2 = CtcMultiBearing(self.M2, self.y2)

    #print("M2",self.M2)
    #print("y2",self.y2)

  def c1_to_c2(self):

    M2=[]
    for mi in self.m:
      m = Interface.convert_intervalVector_c1_to_c2(mi)
      M2.append(m)

    y2=[]
    for yi in self.y:
      y = Interface.convert_interval_c1_to_c2(yi)
      y2.append(y)

    return M2,y2

  def contract(self, x):
    
    x2= Interface.convert_intervalVector_c1_to_c2(x)
    x2 = self.ctc2.contract(x2)

    return Interface.convert_intervalVector_c2_to_c1(x2)


class ContractorNode(Node):
    def __init__(self):
        super().__init__('contractor_node')
        """
        PARAMETERS
        """
        self.debug = False
        self.run_rate = 50.0
        self.show_on_vibes = True

        """
        Vibes Visuals
        """
        if self.show_on_vibes:
            beginDrawing()
            self.fig_map = VIBesFigMap("Positions Tube")
            self.fig_map.set_properties(100,100,500,500)
            self.fig_map.axis_limits(-20,25,-20,25)
            self.fig_x = VIBesFigTubeVector("Positions tubes")
            self.fig_x.set_properties(450, 50, 800, 400)
            self.fig_vx = VIBesFigTubeVector("Speed tubes")
            self.fig_vx.set_properties(450, 50, 800, 400)

        """
        Variables, initialized once first message received.
        """
        self.dt=0.05 #dt for tube
        self.t_tube_delay = 60.0
        self.t_start = None
        self.tdomain= None # c1.Interval(t_now,t_now + t_tube_delay)
        self.Xpsi= None # c1.Tube(tdomain,dt)
        self.Xxy= None # c1.TubeVector(tdomain,dt,2)
        self.v= None # c1.TubeVector(tdomain,dt,2)
        self.node_initialized = False
        #we save last values times received to avoid errors when updating a tube 2 times the same values
        self.last_t_xy = -1.0
        self.last_t_vt = -1.0
        self.last_t_psit = -1.0
        self.last_t_measurements = -1.0
        
        """
        Messages (Updated by subscriptions)
        """
        self.box_stamped_position = None # ROS2 BoxMsgStamped
        self.box_stamped_orientation = None # ROS2 BoxMsgStamped
        self.box_stamped_velocity = None # ROS2 BoxMsgStamped
        self.box_list_stamped_landmarks = None # ROS2 BoxListStampedMsg
        self.box_position_contracted = None # ROS2 BoxMsgStamped

        """
        CONTRACTORS
        """
        # Gonio Contractors
        # initialise le reseaux de contracteur
        self.cn= c1.ContractorNetwork()
        self.ctc_deriv = c1.CtcDeriv()
        self.ctc_eval=c1.CtcEval()

        """
        ROS2
        """
        self.box_stamped_position_raw_sub = self.create_subscription(BoxMsgStamped,'/it/position',self.box_position_raw_callback,10)
        self.box_stamped_orientation_raw_sub = self.create_subscription(BoxMsgStamped,'/it/orientation',self.box_orientation_raw_callback,10)
        self.box_stamped_velocity_raw_sub = self.create_subscription(BoxMsgStamped,'/it/velocity',self.box_velocity_raw_callback,10)
        self.box_stamped_landmarks_raw_sub = self.create_subscription(BoxListStampedMsg,'/it/landmarks',self.box_landmarks_raw_callback,10)
        self.publisher_contracted_position = self.create_publisher(BoxMsgStamped, '/it/contracted/position', 10)
        
        #main loop
        self.create_timer(1.0/self.run_rate, self.run)

    def box_position_raw_callback(self, msg):
        if self.box_stamped_position is None:
            self.init_tube(msg)
            self.node_initialized = True
        self.box_stamped_position = msg
        if self.debug:
            self.get_logger().info(f"Received Position: {str(format_box(msg,3))}")

    def box_orientation_raw_callback(self, msg):
        self.box_stamped_orientation = msg
        if self.debug:
            self.get_logger().info(f"Received Orientation: {str(format_box(msg,3))}")

    def box_velocity_raw_callback(self, msg):
        self.box_stamped_velocity = msg
        if self.debug:
            self.get_logger().info(f"Received Velocity: {str(format_box(msg,3))}")

    def box_landmarks_raw_callback(self, msg):
        self.box_list_stamped_landmarks = msg
        if self.debug:
            debug_txt = "Received Landmarks: "
            for box in msg.boxes:
                debug_txt += f"\n{str(format_box(box,3))}"
            self.get_logger().info(debug_txt)

    def init_tube(self,first_box_stamped_position):
        self.t_start = time_msg_to_float(first_box_stamped_position.header.stamp) #we keep in memory the time of the robot when we started
        self.tdomain= c1.Interval(0.0,self.t_tube_delay)

        self.Xpsi= c1.Tube(self.tdomain,self.dt)
        self.Xxy= c1.TubeVector(self.tdomain,self.dt,2)
        self.v= c1.TubeVector(self.tdomain,self.dt,2)

        #set initial reference point
        pos_interval_vector = box_msg_to_interval_vector(first_box_stamped_position)
        x_truth = pos_interval_vector[0].lb()+(pos_interval_vector[0].ub()-pos_interval_vector[0].lb())/2.0
        y_truth = pos_interval_vector[1].lb()+(pos_interval_vector[1].ub()-pos_interval_vector[1].lb())/2.0
        x_interval = c1.Interval([x_truth,x_truth])
        y_interval = c1.Interval([y_truth,y_truth])
        xy = c1.IntervalVector([x_interval,y_interval])
        self.Xxy.set(xy,0.0)

        #add to contractore network
        self.cn.add(self.ctc_deriv, [self.Xxy, self.v])  # Contrainte entre position et vitesse

        #init Vibes
        if self.show_on_vibes:
            self.fig_map.add_tube(self.Xxy, "[x](.)", 0, 1) # x[0] selon x
            self.fig_x.add_tube(self.Xxy, "[x](.)")
            self.fig_vx.add_tube(self.v, "[v](.)")


    def contract(self,t_vt,vt,t_psit,psit,t_measurements,pos_measurements,bearing_measurements):
        #Add data that are in the wanted time domain, and contract (we also checked the data as not already been given to the network)
        try_contract = False
        if is_in_tdomain(self.tdomain,t_vt) and t_vt != self.last_t_vt:
            self.cn.add_data(self.v, t_vt,vt)
            try_contract = True
        if is_in_tdomain(self.tdomain,t_psit) and t_psit != self.last_t_psit:
            self.cn.add_data(self.Xpsi, t_psit, psit)
            try_contract = True
        """for i in range(len(bearing_measurements)):
            if is_in_tdomain(self.tdomain,t_measurements) and t_measurements != self.last_t_measurements:
                mi = pos_measurements[i]
                y = bearing_measurements[i]
                p = c1.IntervalVector(2)
                a = c1.Interval()
                # On peut ajouter de pecimisme sur mi et y avant que je les mais dans le contracteur
                ctc_gonio = Ctc_gonio([mi], [y])
                self.cn.add(self.ctc_eval, [c1.Interval(t_measurements), p, self.Xxy])  # Constrain position at t
                self.cn.add(self.ctc_eval, [c1.Interval(t_measurements), a, self.Xpsi])  # Constrain position at t
                self.cn.add(ctc_gonio, [p,a])  # Apply bearing constraint
                try_contract = True
                """
        
        if try_contract:
            self.cn.contract()

            #Extract results
            contracted_x = self.Xxy[0].slice(t_vt).input_gate()
            contracted_y = self.Xxy[1].slice(t_vt).input_gate()
            contracted_a = self.Xpsi.slice(t_psit).input_gate()

            #update vibes
            if self.show_on_vibes:
                self.fig_map.draw_box(c1.IntervalVector([contracted_x,contracted_y]))
                self.fig_x.show(False)
                self.fig_vx.show(False)

            if self.debug:
                self.get_logger().info(f"New datas contracted!")

            return contracted_x, contracted_y, contracted_a
        
        else: #No new datas to contract
            if self.debug:
                self.get_logger().info(f"No new datas to contract...")
            return None, None, None

    def publish_position_from_state(self,x_state):
        err_x = (x_state[0].ub() - x_state[0].lb())/2.0
        err_y = (x_state[1].ub() - x_state[1].lb())/2.0
        err_z = 0.0
        mx = x_state[0].lb() + err_x
        my = x_state[1].lb() + err_y
        mz = 0.0
        self.box_position_contracted = get_box(self.box_stamped_position.header.stamp,self.box_stamped_position.header.frame_id,mx,my,mz,err_x,err_y,err_z,name="contracted_boat")
        self.publisher_contracted_position.publish(self.box_position_contracted)
        if self.debug:
            self.get_logger().info(f"New_state: {str(x_state)}")
            self.get_logger().info(f"New position Published: {str(format_box(self.box_position_contracted,3))}")

    def run(self):
        if self.node_initialized and self.box_stamped_position is not None and self.box_stamped_orientation is not None and self.box_list_stamped_landmarks is not None and self.box_stamped_velocity is not None:
            #Get Interval objects for robot
            pos_interval_vector = box_msg_to_interval_vector(self.box_stamped_position)
            speed_interval_vector = box_msg_to_interval_vector(self.box_stamped_velocity)
            orientation_interval_vector = box_msg_to_interval_vector(self.box_stamped_orientation)
            #convert to wanted shape and extract relative time of each data
            t_xy = time_msg_to_float(self.box_stamped_position.header.stamp) - self.t_start
            xy = c1.IntervalVector([pos_interval_vector[0],pos_interval_vector[1]]) #not used, we contract inf,inf box
            
            t_psit = time_msg_to_float(self.box_stamped_orientation.header.stamp) - self.t_start
            psit = orientation_interval_vector[2]

            t_vt = time_msg_to_float(self.box_stamped_velocity.header.stamp) - self.t_start
            vt_boat_frame = c1.IntervalVector([speed_interval_vector[0],speed_interval_vector[1]])
            vt = convert_to_world(vt_boat_frame,psit) #psit may be wrong here, because probably different time than the speed message, we should keep in memory all the heading and their time? Interpolate?
            
            #Get Interval objects for landmarks
            t_measurements = time_msg_to_float(self.box_list_stamped_landmarks.header.stamp) - self.t_start #all same time
            pos_measurements = []
            bearing_measurements = []
            for landmark_msg in self.box_list_stamped_landmarks.boxes:
                landmark = box_msg_to_interval_vector(landmark_msg)
                pos_measurements.append(c1.IntervalVector([landmark[0],landmark[1]]))
                bearing_measurements.append(landmark[2])

            #contract and publish
            """
            And any contraction strategy here
            """
            contracted_x, contracted_y, contracted_a = self.contract(t_vt,vt,t_psit,psit,t_measurements,pos_measurements,bearing_measurements)
            contracted_state = c1.IntervalVector([contracted_x,contracted_y,contracted_a])

            #save last times for values
            self.last_t_xy = t_xy
            self.last_t_vt = t_vt
            self.last_t_psit = t_psit
            self.last_t_measurements = t_measurements

            #Publish
            if contracted_x is not None:
                self.publish_position_from_state(contracted_state)

def is_in_tdomain(tdomain,t):
    return t>=tdomain.lb() and t<=tdomain.ub()

def convert_to_world(speed_interval_vector,bot_heading):
        v_norm = speed_interval_vector[0] #interval
        x_speed = v_norm*cos(bot_heading) #interval 
        y_speed = v_norm*sin(bot_heading) #interval
        return c1.IntervalVector([x_speed,y_speed])

def box_msg_to_interval_vector(msg) :
    interval_list = []
    for interval_msg in msg.intervals:
        interval = interval_msg_to_interval(interval_msg)
        interval_list.append(interval)
    interval_vector = c1.IntervalVector(interval_list)
    return interval_vector

def interval_msg_to_interval(msg):
    interval = c1.Interval(msg.start,msg.end)
    return interval

def format_box(box_msg,precision):
    """Format a BoxMsg or BoxStampedMsg as a list of [start, end] pairs."""
    return [[round(interval.start,precision), round(interval.end,precision)] for interval in box_msg.intervals]

def get_box(timestamp,frame,x,y,z,err_x,err_y,err_z,name="None"):
    box = BoxMsgStamped()
    box.name = name
    box.header = Header(stamp=timestamp, frame_id=frame)
    intervalx = to_interval_msg(x,err_x,"x")
    intervaly = to_interval_msg(y,err_y,"y")
    intervalz = to_interval_msg(z,err_z,"z")
    box.intervals = [intervalx, intervaly, intervalz]
    return box

def to_interval_msg(val,error,name="None"):
    return IntervalMsg(name=name, start=val-abs(error), end=val+abs(error))

def float_to_time_msg(t_float):
    # Convert t_sim into a ROS2 Time message
    t_sim_msg = Time()
    t_sim_msg.sec = int(t_float)  # Whole seconds
    t_sim_msg.nanosec = int((t_float - t_sim_msg.sec) * 1e9)  # Remaining nanoseconds
    return t_sim_msg

def time_msg_to_float(time_msg):
    # Convert a ROS2 Time message into a float
    return time_msg.sec + time_msg.nanosec * 1e-9

def main(args=None):
    rclpy.init(args=args)
    contractor_node = ContractorNode()
    rclpy.spin(contractor_node)
    contractor_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()