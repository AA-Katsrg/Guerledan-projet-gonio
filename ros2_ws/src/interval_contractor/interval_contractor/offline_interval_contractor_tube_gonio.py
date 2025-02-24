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
        beginDrawing()
        self.fig_map = VIBesFigMap("Positions Tube")
        self.fig_map.set_properties(100,100,500,500)
        self.fig_map.axis_limits(-20,25,-10,15)
        self.fig_x = VIBesFigTubeVector("Speed tubes")
        self.fig_x.set_properties(450, 50, 800, 400)
        self.dt=0.01 #dt for tube
        self.t_tube_delay = 15.0
        self.t_start = None
        self.tdomain= None # c1.Interval(t_now,t_now + t_tube_delay)
        self.Xpsi= None # c1.Tube(tdomain,dt)
        self.Xxy= None # c1.TubeVector(tdomain,dt,2)
        self.v= None # c1.TubeVector(tdomain,dt,2)
        self.node_initialized = False
        self.cn= c1.ContractorNetwork()
        self.ctc_deriv = c1.CtcDeriv()
        self.ctc_eval=c1.CtcEval()
        self.init_tube()

        """self.dt=0.01
        self.tdomain= c1.Interval(0,15)
        # Initial pose x0=(0,0,2)
        self.x0 = (0,0,2)
        # System input
        self.u_truth = c1.Trajectory(self.tdomain, c1.TFunction("3*(sin(t)^2)+t/100"), self.dt)
        # Actual trajectories (state + derivative)
        self.v_truth = c1.TrajectoryVector(3)
        self.x_truth = c1.TrajectoryVector(3)
        self.v_truth[2] = self.u_truth
        self.x_truth[2] = self.v_truth[2].primitive() + self.x0[2]
        self.v_truth[0] = 10*c1.cos(self.x_truth[2])
        self.v_truth[1] = 10*c1.sin(self.x_truth[2])
        self.x_truth[0] = self.v_truth[0].primitive() + self.x0[0]
        self.x_truth[1] = self.v_truth[1].primitive() + self.x0[1]
        self.Xpsi=c1.Tube(self.tdomain,self.dt)
        self.Xxy=c1.TubeVector(self.tdomain,self.dt,2)
        self.v=c1.TubeVector(self.tdomain,self.dt,2)
        self.Xxy.set(self.x_truth(0.)[:2],0.)
        self.measurements = {
            10: c1.IntervalVector([-2, -7]),
            5: c1.IntervalVector([1, 15]), 
            # 8: c1.IntervalVector([14, 3]),
            12: c1.IntervalVector([5, -5]),
        }
        self.bearing_measurements = {}
        for t, mi in self.measurements.items():
            x_t = self.x_truth(t)  # Get boat position at time t
            angle = math.atan2(mi[1].mid() - x_t[1], mi[0].mid() - x_t[0]) - x_t[2]
            self.bearing_measurements[t] = c1.Interval(angle)
            print("Bearing Measurements:", self.bearing_measurements[t])
        c1.beginDrawing()
        self.fig_map = c1.VIBesFigMap("Map")
        self.fig_map.set_properties(100,100,500,500)
        self.fig_map.axis_limits(-20,25,-10,15)
        self.fig_map.add_trajectory(self.x_truth, "x", 0, 1)
        self.fig_map.add_tube(self.Xxy, "x", 0, 1)
        # initialise le reseaux de contracteur
        self.cn= c1.ContractorNetwork()
        self.ctc_deriv = c1.CtcDeriv()
        self.ctc_eval=c1.CtcEval()
        self.cn.add(self.ctc_deriv, [self.Xxy, self.v])  # Contrainte entre position et vitesse
        """

        self.t= self.tdomain.lb()

        """
        Publish result via ROS
        """
        self.box_position_contracted = None # ROS2 BoxMsgStamped
        self.publisher_contracted_position = self.create_publisher(BoxMsgStamped, '/it/contracted/position', 10)
        #main loop
        self.create_timer(self.dt, self.run)


    def init_tube(self):
        self.t_start = 0.0
        self.t_tube_delay = 15.0
        self.tdomain= c1.Interval(self.t_start,self.t_start + self.t_tube_delay)

        self.x0 = (0,0,2)
        self.u_truth = c1.Trajectory(self.tdomain, c1.TFunction("3*(sin(t)^2)+t/100"), self.dt)
        self.v_truth = c1.TrajectoryVector(3)
        self.x_truth = c1.TrajectoryVector(3)
        self.v_truth[2] = self.u_truth
        self.x_truth[2] = self.v_truth[2].primitive() + self.x0[2]
        self.v_truth[0] = 10*c1.cos(self.x_truth[2])
        self.v_truth[1] = 10*c1.sin(self.x_truth[2])
        self.x_truth[0] = self.v_truth[0].primitive() + self.x0[0]
        self.x_truth[1] = self.v_truth[1].primitive() + self.x0[1]

        self.Xpsi= c1.Tube(self.tdomain,self.dt)
        self.Xxy= c1.TubeVector(self.tdomain,self.dt,2)
        self.v= c1.TubeVector(self.tdomain,self.dt,2)

        self.Xxy.set(self.x_truth(self.t_start)[:2],self.t_start)

        #add to contractor network
        self.cn.add(self.ctc_deriv, [self.Xxy, self.v])  # Contrainte entre position et vitesse

        #init Vibes
        self.fig_map.add_trajectory(self.x_truth, "x", 0, 1)
        self.fig_map.add_tube(self.Xxy, "x", 0, 1)
        self.fig_x.add_tube(self.v, "[v](.)")
        self.fig_x.show(False)

    def contract(self,t,vt,psit,pos_measurements,bearing_measurements):
        self.cn.add_data(self.v, t,vt)
        self.cn.add_data(self.Xpsi, t, psit)

        self.cn.contract()
        contracted_x = self.Xxy(t)[0]
        contracted_y = self.Xxy(t)[1]
        contracted_a = self.Xpsi(t)

        #update vibes
        self.fig_map.draw_box(self.Xxy(t))
        self.fig_x.show(False)

        return contracted_x, contracted_y, contracted_a

    def publish_position_from_state(self,x_state):
        err_x = (x_state[0].ub() - x_state[0].lb())/2.0
        err_y = (x_state[1].ub() - x_state[1].lb())/2.0
        err_z = 0.0
        mx = x_state[0].lb() + err_x
        my = x_state[1].lb() + err_y
        mz = 0.0
        self.publisher_contracted_position.publish(get_box(self.box_stamped_position.header.stamp,self.box_stamped_position.header.frame_id,mx,my,mz,err_x,err_y,err_z,name="contracted_boat"))

    def run(self):
        # Add the cn.add_data for x and v of the tube
        a = c1.Interval(self.x_truth(self.t)[2])
        vt = c1.IntervalVector([c1.Interval(self.v_truth(self.t)[0]),c1.Interval(self.v_truth(self.t)[1])]).inflate(0)
        contracted_x, contracted_y, contracted_a = self.contract(self.t,vt,a,None,None)
        contracted_state = c1.IntervalVector([contracted_x,contracted_y,contracted_a])
        #self.publish_position_from_state(contracted_state)
        self.t+=self.dt

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