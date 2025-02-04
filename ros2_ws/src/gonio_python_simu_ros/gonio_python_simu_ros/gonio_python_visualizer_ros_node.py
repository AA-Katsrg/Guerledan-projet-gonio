import rclpy
from rclpy.node import Node
from interval_analysis_interfaces.msg import Interval as IntervalMsg
from interval_analysis_interfaces.msg import BoxStamped as BoxMsgStamped
from interval_analysis_interfaces.msg import Box as BoxMsg
from interval_analysis_interfaces.msg import BoxListStamped as BoxListStampedMsg
from std_msgs.msg import Header
from builtin_interfaces.msg import Time
from gonio_python_simu_ros.simu import Simulation
from gonio_python_simu_ros.boat import Boat
from gonio_python_simu_ros.buoy import Buoy
from gonio_python_simu_ros.calcul_tools import *
from gonio_python_simu_ros.draw import *
import math
import random

class GonioPythonVisualizerRosNode(Node):
    def __init__(self):
        super().__init__('gonio_python_visualizer_ros_node')

        """
        PARAMETERS
        """
        self.debug = False #print debug in terminal
        self.draw_rate = 30.0 #Hz

        """
        INITIALISATIONS
        """
        #objects, will be updated based on received intervals
        self.sea_objects = []
        #visuals
        self.s = 7.0 #will be updated depending on objects positions
        self.fig, self.ax = init_figure(-self.s, self.s, -self.s, self.s, id="Gonio Visualizer")

        """
        Dynamic data (Updated by subscribers)
        """
        self.box_stamped_position = None # ROS2 BoxMsgStamped
        self.box_stamped_orientation = None # ROS2 BoxMsgStamped
        self.box_stamped_velocity = None # ROS2 BoxMsgStamped
        self.box_list_stamped_landmarks = None # ROS2 BoxListStampedMsg
        self.box_position_contracted = None # ROS2 BoxMsgStamped

        """
        ROS2 Setup
        """
        # Subscribers
        self.box_stamped_posiion_contracted_sub = self.create_subscription(BoxMsgStamped,'/it/contracted/position',self.box_position_contracted_callback,10)
        self.box_stamped_posiion_raw_sub = self.create_subscription(BoxMsgStamped,'/it/position',self.box_position_raw_callback,10)
        self.box_stamped_orientation_raw_sub = self.create_subscription(BoxMsgStamped,'/it/orientation',self.box_orientation_raw_callback,10)
        self.box_stamped_velocity_raw_sub = self.create_subscription(BoxMsgStamped,'/it/velocity',self.box_velocity_raw_callback,10)
        self.box_stamped_landmarks_raw_sub = self.create_subscription(BoxListStampedMsg,'/it/landmarks',self.box_landmarks_raw_callback,10)

        #drawing loop
        self.create_timer(1.0 / self.draw_rate, self.draw_data)

        self.get_logger().info(f"Visualizer started....")

    def box_position_contracted_callback(self, msg):
        self.box_position_contracted = msg
        if self.debug:
            self.get_logger().info(f"Received Contracted Position: {str(format_box(msg,3))}")

    def box_position_raw_callback(self, msg):
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

    def draw_data(self):
        #Update available boxes to draw for this frame
        if self.box_stamped_position is None:
            self.box_stamped_position = get_box(float_to_time_msg(-1.0),"map",0.0,0.0,0.0,float('inf'),float('inf'),float('inf'),name="fake_boat_position")
        if self.box_stamped_orientation is None:
            self.box_stamped_orientation = get_box(float_to_time_msg(-1.0),"map",0.0,0.0,0.0,float('inf'),float('inf'),float('inf'),name="fake_bot_orientation")
        draw_box_list = [] #can contain None values if not yet initialized
        draw_box_list.append(self.box_stamped_position)
        draw_box_list.append(self.box_position_contracted)
        if self.box_list_stamped_landmarks is not None:
            for landmark_box in self.box_list_stamped_landmarks.boxes:
                draw_box_list.append(landmark_box)

        #Create objects
        self.sea_objects = []
        for i in range(len(draw_box_list)):
            if draw_box_list[i] is not None:
                if i == 0: #should correspond to the boat position
                    self.add_boat_from_box(draw_box_list[i],self.box_stamped_orientation)
                elif i > 1: #we ignore contracted boat position
                    self.add_buoy_from_box(draw_box_list[i])

        #draw objects
        clear(self.ax)
        for sea_object in self.sea_objects:
            sea_object.draw(self.ax, 2)
        if len(self.sea_objects) > 0:
            if self.box_stamped_position.header.stamp.sec > 0.0: #if we have a boat
                self.ax.set_xlim(self.sea_objects[0].x-self.s, self.sea_objects[0].x+self.s)
                self.ax.set_ylim(self.sea_objects[0].y-self.s, self.sea_objects[0].y+self.s)
            else:
                self.ax.set_xlim(-self.s, self.s)
                self.ax.set_ylim(-self.s, self.s)

        #Draw intervals
        draw_box_lines(self.ax, self.box_stamped_position, color='red', label=self.box_stamped_position.name)
        for box in draw_box_list[1:]: #we ignore boat
            if box is not None:
                draw_box_lines(self.ax, box, color='red', label="raw_"+box.name)
                if self.box_stamped_position.header.stamp.sec > 0.0: #if we have a boat
                    draw_fov_lines(self.ax, self.sea_objects[0].x, self.sea_objects[0].y, box, color='red', label="raw_"+box.name)
                else:
                    draw_fov_lines(self.ax, 0.0, 0.0, box, color='red', label="raw_"+box.name)
        if self.box_position_contracted is not None:
            draw_box_lines(self.ax, self.box_position_contracted, color='green', label="contracted_boat", pos="down")
        plt.title('Visualizer')

    def add_buoy_from_box(self,box):
        #get position (center of the box)
        x_int = [interval for interval in box.intervals if interval.name == "x"][0]
        center_x = x_int.start + (x_int.end - x_int.start)/2
        y_int = [interval for interval in box.intervals if interval.name == "y"][0]
        center_y = y_int.start + (y_int.end - y_int.start)/2
        self.sea_objects.append(Buoy(333, center_x, center_y, 0, 1, 0, 0))

    def add_boat_from_box(self,box_pos,box_orientation):
        #get position (center of the box)
        x_int = [interval for interval in box_pos.intervals if interval.name == "x"][0]
        center_x = x_int.start + (x_int.end - x_int.start)/2
        y_int = [interval for interval in box_pos.intervals if interval.name == "y"][0]
        center_y = y_int.start + (y_int.end - y_int.start)/2
        #get heading (center of interval)
        center_angle = 0.0
        if box_orientation is not None:
            angle_int = [interval for interval in box_orientation.intervals if interval.name == "z"][0]
            center_angle = angle_int.start + (angle_int.end - angle_int.start)/2
        self.sea_objects.append(Boat(222, center_x, center_y, 0.0, center_angle, 4, 1.75))

def format_box(box_msg,precision):
    """Format a BoxMsg or BoxStampedMsg as a list of [start, end] pairs."""
    return [[round(interval.start,precision), round(interval.end,precision)] for interval in box_msg.intervals]

def draw_box_lines(ax, box_msg, color='red', label=None, pos="top"):
    """
    Draws a square box using simple lines based on a BoxMsg.

    Parameters:
        ax: Matplotlib axis to draw on.
        box_msg: A BoxMsg containing position interval data.
        color: Color of the box lines.
        label: Optional label for the box.
    """
    # Extract intervals
    x_interval = [interval for interval in box_msg.intervals if interval.name == "x"][0]
    y_interval = [interval for interval in box_msg.intervals if interval.name == "y"][0]

    # Get box boundaries
    x_min, x_max = x_interval.start, x_interval.end
    y_min, y_max = y_interval.start, y_interval.end

    finite_vals = True
    if np.isinf([x_min, x_max,y_min, y_max]).any():
        x_min, x_max,y_min, y_max = -1.0, 1.0, -1.0, 1.0
        finite_vals = False

    # Define the four corners
    corners = [
        (x_min, y_min),
        (x_max, y_min),
        (x_max, y_max),
        (x_min, y_max),
        (x_min, y_min)  # Close the box
    ]

    # Extract x and y coordinates
    x_vals, y_vals = zip(*corners)

    # Draw the box using simple lines
    linestyle = '-' # Solid line
    if not finite_vals:  # Check if any value in x_vals is infinite
        linestyle=(0, (5, 5))  # Dashed pattern "- - - -"
    ax.plot(x_vals, y_vals, color=color, linestyle=linestyle, linewidth=1)

    # Draw the center point
    center_x, center_y = (x_min + x_max) / 2, (y_min + y_max) / 2
    ax.plot(center_x, center_y, color=color, marker='x')

    # Add label
    if label:
        #width = abs(x_max-x_min)
        height = abs(y_max-y_min)
        x_text = center_x
        y_text = center_y
        if pos == "top":
            y_text += (height/2)+0.30
        elif pos == "down":
            y_text -= (height/2)+0.30
        txt = label
        if not finite_vals:
            txt = "inf"
        ax.text(x_text, y_text, txt, fontsize=10, ha='center', va='center', color=color)

def draw_fov_lines(ax, robot_x, robot_y, box_msg, color='red', linewidth=1.0, label=None):
    """
    Draws two cropped arcs using lines and connects them with radial lines.
    
    Parameters:
    - ax: Matplotlib axis
    - robot_x, robot_y: Position of the robot
    - angle_min, angle_max: Field of view limits (radians)
    - range_min, range_max: Min and max range values
    - color: Line color
    - linewidth: Line thickness
    """
    angle_interval = [interval for interval in box_msg.intervals if interval.name == "angle"][0]
    range_interval = [interval for interval in box_msg.intervals if interval.name == "range"][0]
    angle_min, angle_max = angle_interval.start, angle_interval.end
    range_min, range_max = range_interval.start, range_interval.end

    # Generate points for the inner arc (minimum range)
    theta_inner = np.linspace(angle_min, angle_max, 30)  # Smooth arc
    inner_x = robot_x + range_min * np.cos(theta_inner)
    inner_y = robot_y + range_min * np.sin(theta_inner)
    
    # Generate points for the outer arc (maximum range)
    theta_outer = np.linspace(angle_min, angle_max, 30)  # Smooth arc
    outer_x = robot_x + range_max * np.cos(theta_outer)
    outer_y = robot_y + range_max * np.sin(theta_outer)

    # Draw the inner arc
    ax.plot(inner_x, inner_y, color=color, linewidth=linewidth)

    # Draw the outer arc
    ax.plot(outer_x, outer_y, color=color, linewidth=linewidth)

    # Compute endpoints for the FOV boundaries
    x1_min, y1_min = robot_x + range_min * np.cos(angle_min), robot_y + range_min * np.sin(angle_min)
    x1_max, y1_max = robot_x + range_max * np.cos(angle_min), robot_y + range_max * np.sin(angle_min)
    x2_min, y2_min = robot_x + range_min * np.cos(angle_max), robot_y + range_min * np.sin(angle_max)
    x2_max, y2_max = robot_x + range_max * np.cos(angle_max), robot_y + range_max * np.sin(angle_max)

    # Draw the two radial lines to connect the arcs
    ax.plot([x1_min, x1_max], [y1_min, y1_max], color=color, linewidth=linewidth)  # Left FOV boundary
    ax.plot([x2_min, x2_max], [y2_min, y2_max], color=color, linewidth=linewidth)  # Right FOV boundary

    if label:
        x_text = (min([x1_min,x1_max,x2_min,x2_max])+max([x1_min,x1_max,x2_min,x2_max]))/2
        y_text = min([y1_min,y1_max,y2_min,y2_max])-0.30
        ax.text(x_text, y_text, label, fontsize=10, ha='center', va='center', color=color)

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

def main(args=None):
    rclpy.init(args=args)
    gonio_python_simu_ros_node = GonioPythonVisualizerRosNode()
    rclpy.spin(gonio_python_simu_ros_node)
    gonio_python_simu_ros_node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
