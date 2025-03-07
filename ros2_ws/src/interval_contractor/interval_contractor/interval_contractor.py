import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64
from geometry_msgs.msg import PoseArray, Pose
import codac as c1
import codac2 as c2
from vibes import vibes
import math
import numpy as np
import interval_contractor.interface_codac as Interface
from interval_analysis_interfaces.msg import Interval as IntervalMsg
from interval_analysis_interfaces.msg import BoxStamped as BoxMsgStamped
from interval_analysis_interfaces.msg import Box as BoxMsg
from interval_analysis_interfaces.msg import BoxListStamped as BoxListStampedMsg
import time

class CtcMultiBearing(c2.Ctc):
    def __init__(self, m_, y_):
        c2.Ctc.__init__(self, 3)
        self.m = m_
        self.y = y_

    def contract(self, x):
        n = len(self.m)
        A = c2.IntervalMatrix(n, 2) #c2 est codac2
        b = c2.IntervalVector(n)
        p = c2.IntervalVector([x[0], x[1]])
        
        for i in range(n):
            A[i, 0] = c2.sin(x[2] + self.y[i])
            A[i, 1] = -c2.cos(x[2] + self.y[i])
            b[i] = self.m[i][0] * c2.sin(x[2] + self.y[i])
            - self.m[i][1] * c2.cos(x[2] + self.y[i])
        
        c2.MulOp.bwd(b, A, p)
        x.put(0, p)
        return x

class CtcGonio(c1.Ctc):
    def __init__(self, M_, y_):
        c1.Ctc.__init__(self, 3)
        self.m = M_
        self.y = y_
        self.M2, self.y2 = self.c1_to_c2()
        self.ctcc2 = CtcMultiBearing(self.M2, self.y2)

    def c1_to_c2(self):
        M2 = [Interface.convert_intervalVector_c1_to_c2(mi) for mi in self.m]
        y2 = [Interface.convert_interval_c1_to_c2(yi) for yi in self.y]
        return M2, y2

    def contract(self, x):
        x2 = Interface.convert_intervalVector_c1_to_c2(x)
        x2_ = self.ctcc2.contract(x2)
        x.put(0, Interface.convert_intervalVector_c2_to_c1(x2_))
        return x

class GonioNode(Node):
    def __init__(self):
        super().__init__('gonio_node')
        self.subscription_cap = self.create_subscription(BoxMsgStamped, '/it/orientation', self.cap_callback, 10)
        self.subscription_landmarks = self.create_subscription(BoxListStampedMsg, '/it/landmarks', self.landmarks_callback, 10)
        self.subscription_velocity = self.create_subscription(BoxMsgStamped, '/it/velocity', self.velocity_callback, 10)
        self.publisher = self.create_publisher(BoxMsgStamped, '/it/contracted/position', 10)
        self.cap = c1.Interval.EMPTY_SET
        self.landmarks_msg = None
        contractor_rate = 1 #Hz
        self.create_timer(1.0 / contractor_rate, self.try_contract)
        self.velocity = 0
        self.prev_t_slice = time.time()
        self.cap_slice = c1.Interval.EMPTY_SET
        #self.integral = c1.IntervalVector([c1.Interval(0, 0), c1.Interval(0, 0)])
        self.v_slice = c1.IntervalVector.empty(2)
        self.v_robot_slice = c1.Interval.EMPTY_SET
        self.x_slice = c1.IntervalVector([c1.Interval(0, 0), c1.Interval(0, 0)])
        self.x_t = c1.IntervalVector([c1.Interval(-6, 6), c1.Interval(-6, 6)])
        self.x_slice_to_contract = c1.IntervalVector([c1.Interval(0, 0), c1.Interval(0, 0), c1.Interval(0, 2*np.pi)])
        
        #pour afficher la vitesse
        self.t = 0
        self.t_prev = 0
        self.vx = []
        self.v_slice_x = []
        vibes.beginDrawing()
        vibes.newFigure("fig")
        


    def cap_callback(self, msg):
        _, _, self.cap = box_msg_to_interval(msg)
        #if self.cap_slice.is_empty() :
        #    self.cap_slice = self.cap
        self.cap_slice |= self.cap
        #self.get_logger().info(f"Orientation reçue: {self.cap_slice}")

    def landmarks_callback(self, msg):
        self.landmarks_msg = msg
        #self.get_logger().info(f"Landmarks reçus: {self.landmarks_msg}")


    def velocity_callback (self, msg) :
        self.velocity, _, _ = box_msg_to_interval(msg)
        #self.get_logger().info(f"Vitesse reçus: {self.v_robot_slice}")
        #if self.v_robot_slice.is_empty() :
        #    self.v_robot_slice = self.velocity
        #print(self.v_robot_slice.is_empty())
        self.v_robot_slice |= self.velocity
        
        #pour afficher les vitesses
        self.vx.append([self.t, (((self.velocity * c1.cos(self.cap)).lb() + (self.velocity * c1.cos(self.cap)).ub()) /2)])
        self.t += 1
        
            
        
    

    def try_contract(self):
        if self.landmarks_msg is not None :
            #M = [c1.IntervalVector((lm[0], lm[1])) for lm in self.landmarks_msg]
            #y = [c1.Interval(math.atan2(lm[1], lm[0]) - self.cap).inflate(0.05) for lm in self.landmarks]
            
            #print("rentre dans la boucle")
            y = []
            X, Y, A, R = list_landmark_to_interval(self.landmarks_msg)
            M = []
            for i in range (len(X)) :
                M.append(c1.IntervalVector((X[i], Y[i])))
                y.append(A[i])
            #print(len(y))
            #print(len(M))
            
            #self.x = c1.IntervalVector([c1.Interval(-6, 6), c1.Interval(-6, 6), self.cap])
            #self.x += self.integral 
            t = time.time()
            
            self.get_logger().info(f"Vitesse robot reçue: {self.v_robot_slice}")
            self.get_logger().info(f"Orientation reçue au cours du temps: {self.cap_slice}")
            
            self.v_slice = c1.IntervalVector([c1.Interval(self.v_robot_slice*c1.cos(self.cap_slice)), c1.Interval(self.v_robot_slice*c1.sin(self.cap_slice))])
            #self.get_logger().info(f"Vitesse reçue: {self.v_slice}")
            #self.get_logger().info(f"Temps entre deux iteration: {t- self.prev_t_slice}")

            #pour le debuggage
            self.v_slice_x = [self.v_slice[0].lb(), self.v_slice[0].ub()]
        
            self.t += 1
            
            self.x_slice = c1.IntervalVector(self.x_t + (t-self.prev_t_slice)*self.v_slice)
            self.x_t_to_contract = c1.cart_prod(self.x_slice, c1.IntervalVector([self.cap]))
            self.prev_t_slice = t
            self.v_slice = c1.IntervalVector.empty(2)
            self.cap_slice = c1.Interval.EMPTY_SET
            self.x_t = self.x_slice
            #print(self.x_t[0].ub() - self.x_t[0].lb() + self.x_t[1].ub() - self.x_t[1].lb())
            if len(y) != 0 :
                x_contract = CtcGonio(M, y).contract(self.x_t_to_contract)
                #print(x_contract[0], x_contract[1])
                #print(x_contract)
                self.x_t = c1.IntervalVector([x_contract[0], x_contract[1]])
                self.cap = x_contract[2]
            
            self.get_logger().info(f"Position contractée: x=[{self.x_t[0].lb()}, {self.x_t[0].ub()}], y=[{self.x_t[1].lb()}, {self.x_t[1].ub()}]")
            
            contracted_box = BoxMsgStamped()
            contracted_box.name = "contracted_position"
            contracted_box.header.stamp = self.get_clock().now().to_msg()
            contracted_box.header.frame_id = "map"

            x_interval = IntervalMsg(name="x", start=self.x_t[0].lb(), end=self.x_t[0].ub())
            y_interval = IntervalMsg(name="y", start=self.x_t[1].lb(), end=self.x_t[1].ub())

            contracted_box.intervals = [x_interval, y_interval]
            self.publisher.publish(contracted_box)
            #self.get_logger().info(f'Contracted position: [{x[0].lb()}, {x[0].ub()}], [{x[1].lb()}, {x[1].ub()}]')
            
            #affichage des vitesses
            #vibes.drawLine(self.v_slice_x, color='r')
            vibes.drawBox(self.t_prev, self.t, self.v_slice_x[0], self.v_slice_x[1], color = 'r')
            vibes.drawLine(self.vx, color='b')
            self.t_prev = self.t


def box_msg_to_interval(msg) :
    x_msg = msg.intervals[0]
    y_msg = msg.intervals[1]
    z_msg = msg.intervals[2]
    x, y, z = c1.Interval(x_msg.start, x_msg.end), c1.Interval(y_msg.start, y_msg.end), c1.Interval(z_msg.start, z_msg.end)
    return x, y, z

def one_landmark_to_interval(msg) :
    x_msg, y_msg, a_msg, r_msg = msg.intervals
    x, y, a, r = c1.Interval(x_msg.start, x_msg.end), c1.Interval(y_msg.start, y_msg.end), c1.Interval(a_msg.start, a_msg.end), c1.Interval(r_msg.start, r_msg.end)
    return x, y, a, r

def list_landmark_to_interval(msg) :
    X, Y, A, R = [], [], [], []
    for landmark_msg in msg.boxes :
        x, y, a, r = one_landmark_to_interval(landmark_msg)
        X.append(x)
        Y.append(y)
        A.append(a)
        R.append(r)
    return X, Y, A, R
        

def main(args=None):
    rclpy.init(args=args)
    node = GonioNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()