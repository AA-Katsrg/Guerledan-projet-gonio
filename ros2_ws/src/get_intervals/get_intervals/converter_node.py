import rclpy
from rclpy.node import Node
from interval_analysis_interfaces.msg import Interval as IntervalMsg
from interval_analysis_interfaces.msg import BoxStamped as BoxMsgStamped
from std_msgs.msg import Header
from builtin_interfaces.msg import Time
from sbg_driver.msg import SbgEkfEuler
from sbg_driver.msg import SbgGpsHdt
from sbg_driver.msg import SbgGpsPos
from sbg_driver.msg import SbgGpsVel
from my_drone_interfaces.msg import DVL
import numpy as np

class ConverterNode(Node):
    def __init__(self):
        super().__init__('converter_node')
        """
        PARAMETERS
        """
        self.debug = False
        self.use_gps_pos = True #if false, we just send an infinite box, othewise, we use the GPS estimations to have a first 'contraction'
        self.gps_ref_pose = None

        """
        Orientation (EKF Euler)
        """
        # Subscriber for messages
        self.orientation_ekf_sub = self.create_subscription(SbgEkfEuler,'sbg/ekf_euler',self.orientation_ekf_callback,10)
        # Publishers for each messages
        self.box_stamped_orientation_ekf_pub = self.create_publisher(BoxMsgStamped, '/it/orientation_ekf', 10)
        #variables
        self.orientation_ekf_msg = None
        self.box_orientation_ekf_msg = None

        """
        Orientation (GPS)
        """
        # Subscriber for messages
        self.orientation_gps_sub = self.create_subscription(SbgGpsHdt, '/sbg/gps_hdt', self.orientation_gps_callback, 10)
        # Publisher for processed GPS orientation data
        self.box_stamped_orientation_gps_pub = self.create_publisher(BoxMsgStamped, '/it/orientation', 10)
        # Variables
        self.orientation_gps_msg = None
        self.box_orientation_gps_msg = None

        """
        Position (GPS)
        """
        # Subscriber for messages
        self.position_gps_sub = self.create_subscription(SbgGpsPos, '/sbg/gps_pos', self.position_gps_callback, 10)
        # Publisher for processed GPS position data
        self.box_stamped_position_gps_pub = self.create_publisher(BoxMsgStamped, '/it/position', 10)
        # Variables
        self.position_gps_msg = None
        self.box_position_gps_msg = None
        self.ref_pose = None
 
        """
        Velocity (DVL)
        """
        # Subscriber for messages
        self.velocity_dvl_sub = self.create_subscription(DVL, '/dvl/data', self.velocity_dvl_callback, 10)
        # Publisher for processed DVL velocity data
        self.box_stamped_velocity_dvl_pub = self.create_publisher(BoxMsgStamped, '/it/velocity', 10)
        # Variables
        self.velocity_dvl_msg = None
        self.box_velocity_dvl_msg = None

        """
        Velocity (GPS)
        """
        # Subscriber for messages
        self.velocity_gps_sub = self.create_subscription(SbgGpsVel, '/sbg/gps_vel', self.velocity_gps_callback, 10)
        # Publisher for processed GPS velocity data
        self.box_stamped_velocity_gps_pub = self.create_publisher(BoxMsgStamped, '/it/velocity_gps', 10)
        # Variables
        self.velocity_gps_msg = None
        self.box_velocity_gps_msg = None

        """
        Reference GPS Pose publication
        """
        # Publisher for reference GPS pose
        self.ref_pose_pub = self.create_publisher(SbgGpsPos, '/it/ref_pose', 10)

    """
    Subscribers to raw data
    """
    def orientation_ekf_callback(self, msg):
        self.orientation_ekf_msg = msg
        self.box_orientation_ekf_msg = get_box_orientation_ekf(self.orientation_ekf_msg)
        self.box_stamped_orientation_ekf_pub.publish(self.box_orientation_ekf_msg)
        if self.debug:
            self.get_logger().info(f"Received EKF Orientation: {msg}")
            self.get_logger().info(f"Sent Box EKF Orientation: {format_box(self.box_orientation_ekf_msg,3)}")

    def orientation_gps_callback(self, msg):
        self.orientation_gps_msg = msg
        self.box_orientation_gps_msg = get_box_orientation_gps(self.orientation_gps_msg)
        self.box_stamped_orientation_gps_pub.publish(self.box_orientation_gps_msg)
        if self.debug:
            self.get_logger().info(f"Received GPS Orientation: {msg}")
            self.get_logger().info(f"Sent Box GPS Orientation: {format_box(self.box_orientation_gps_msg,3)}")

    def position_gps_callback(self, msg):
        self.position_gps_msg = msg
        if self.ref_pose == None:
            self.gps_ref_pose = msg
        self.box_position_gps_msg = get_box_position_gps(self.position_gps_msg,self.gps_ref_pose,self.use_gps_pos)
        self.box_stamped_position_gps_pub.publish(self.box_position_gps_msg)
        self.ref_pose_pub.publish(self.ref_pose)
        if self.debug:
            self.get_logger().info(f"Published Reference GPS Pose: {self.ref_pose}")
            self.get_logger().info(f"Received GPS Position: {msg}")
            self.get_logger().info(f"Sent Box GPS Position: {format_box(self.box_position_gps_msg,3)}")

    def velocity_dvl_callback(self, msg):
        self.velocity_dvl_msg = msg
        self.box_velocity_dvl_msg = get_box_velocity_dvl(self.velocity_dvl_msg)
        self.box_stamped_velocity_dvl_pub.publish(self.box_velocity_dvl_msg)
        if self.debug:
            self.get_logger().info(f"Received DVL Velocity: {msg}")
            self.get_logger().info(f"Sent Box DVL Velocity: {format_box(self.box_velocity_dvl_msg,3)}")

    def velocity_gps_callback(self, msg):
        self.velocity_gps_msg = msg
        self.box_velocity_gps_msg = get_box_velocity_gps(self.velocity_gps_msg)
        self.box_stamped_velocity_gps_pub.publish(self.box_velocity_gps_msg)
        if self.debug:
            self.get_logger().info(f"Received GPS Velocity: {msg}")
            self.get_logger().info(f"Sent Box GPS Velocity: {format_box(self.box_velocity_gps_msg,3)}")

def get_box_orientation_ekf(msg):
    # Process EKF orientation message and return a BoxMsgStamped
    x = msg.angle.x
    y = msg.angle.y
    z = msg.angle.z
    err_x = msg.accuracy.x
    err_y = msg.accuracy.y
    err_z = msg.accuracy.z
    return get_box(msg.header.stamp,msg.header.frame_id,x,y,z,err_x,err_y,err_z,name="euler_angles")

def get_box_orientation_gps(msg):
    # Process GPS orientation message and return a BoxMsgStamped
    x = np.deg2rad(msg.pitch)
    y = 0.0 #Not given by GPS
    z = -np.deg2rad(msg.true_heading)
    err_x = np.deg2rad(msg.pitch_acc)
    err_y = 0.0
    err_z = np.deg2rad(msg.true_heading_acc)
    return get_box(msg.header.stamp,msg.header.frame_id,x,y,z,err_x,err_y,err_z,name="euler_angles_gps")

def get_box_position_gps(msg,ref_pose_msg,use_gps=True):
    # Process GPS position message and return a BoxMsgStamped
    z = msg.altitude
    x, y = get_ref_dist(msg.longitude,msg.latitude,ref_pose_msg.longitude,ref_pose_msg.latitude)
    err_x = msg.position_accuracy.x
    err_y = msg.position_accuracy.y
    err_z = msg.position_accuracy.z
    if use_gps:
        return get_box(msg.header.stamp,msg.header.frame_id,x,y,z,err_x,err_y,err_z,name="position")
    else:
        return get_box(msg.header.stamp,msg.header.frame_id,0.0,0.0,0.0,float('inf'),float('inf'),float('inf'),name="position")

def get_ref_dist(long, lat, long_ref, lat_ref):
    """
    Compute the local Cartesian (East, North) distance from a reference GPS coordinate.

    Args:
        long (float): Current longitude in degrees.
        lat (float): Current latitude in degrees.
        long_ref (float): Reference longitude in degrees.
        lat_ref (float): Reference latitude in degrees.

    Returns:
        tuple: (x_offset, y_offset) in meters.
    """
    # Convert degrees to radians
    long, lat = np.deg2rad(long), np.deg2rad(lat)
    long_ref, lat_ref = np.deg2rad(long_ref), np.deg2rad(lat_ref)

    # Earth radii (WGS84)
    R_E = 6378137.0  # Equatorial radius in meters
    R_N = 6356752.3  # Polar radius in meters

    # Compute differences
    d_long = long - long_ref
    d_lat = lat - lat_ref

    # Compute local Cartesian coordinates (East, North)
    x_off = d_long * np.cos(lat_ref) * R_E  # East offset (meters)
    y_off = d_lat * R_N                     # North offset (meters)

    return x_off, y_off

def get_box_velocity_dvl(msg):
    # Process DVL velocity message and return a BoxMsgStamped
    x = msg.velocity.x
    y = msg.velocity.y
    z = msg.velocity.z
    err_x = 0.01
    err_y = 0.01
    err_z = 0.01
    if msg.velocity_valid:
        return get_box(msg.header.stamp,msg.header.frame_id,x,y,z,err_x,err_y,err_z,name="speed")
    else:
        return get_box(msg.header.stamp,msg.header.frame_id,0.0,0.0,0.0,float('inf'),float('inf'),float('inf'),name="speed")

def get_box_velocity_gps(msg):
    # Process GPS velocity message and return a BoxMsgStamped
    x = msg.velocity.x
    y = msg.velocity.y
    z = msg.velocity.z
    err_x = msg.velocity_accuracy.x
    err_y = msg.velocity_accuracy.y
    err_z = msg.velocity_accuracy.z
    return get_box(msg.header.stamp,msg.header.frame_id,x,y,z,err_x,err_y,err_z,name="speed_gps")

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
    converter_node = ConverterNode()
    rclpy.spin(converter_node)
    converter_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()