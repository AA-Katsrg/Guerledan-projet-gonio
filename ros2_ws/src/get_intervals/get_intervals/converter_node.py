import rclpy
from rclpy.node import Node
from interval_analysis_interfaces.msg import Interval as IntervalMsg
from interval_analysis_interfaces.msg import BoxStamped as BoxMsgStamped
from geometry_msgs.msg import Vector3Stamped

class ConverterNode(Node):
    def __init__(self):
        super().__init__('converter_node')
        """
        Orientation
        """
        # Subscriber for messages
        self.vector3_orientation_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/angle',self.vector3_orientation_callback,10)
        self.vector3_orientation_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/accuracy',self.vector3_orientation_accuracy_callback,10)
        # Publishers for each messages
        self.box_stamped_orientation_pub = self.create_publisher(BoxMsgStamped, '/it/orientation', 10)
        #variables
        self.vector3_orientation_msg = None
        self.vector3_orientation_accuracy_msg = None

        """
        Position
        """
        # Subscriber for messages
        self.vector3_position_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/position',self.vector3_position_callback,10)
        self.vector3_position_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/position_accuracy',self.vector3_position_accuracy_callback,10)
        # Publishers for each messages
        self.box_stamped_position_pub = self.create_publisher(BoxMsgStamped, '/it/position', 10)
        #variables
        self.vector3_position_msg = None
        self.vector3_position_accuracy_msg = None

        """
        Velocity
        """
        # Subscriber for messages
        self.vector3_velocity_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/velocity',self.vector3_velocity_callback,10)
        self.vector3_velocity_sub = self.create_subscription(Vector3Stamped,'sbg/ekf_euler/velocity_accuracy',self.vector3_velocity_accuracy_callback,10)
        # Publishers for each messages
        self.box_stamped_velocity_pub = self.create_publisher(BoxMsgStamped, '/it/velocity', 10)
        #variables
        self.vector3_velocity_msg = None
        self.vector3_velocity_accuracy_msg = None

    """
    Orientation
    """
    def vector3_orientation_accuracy_callback(self, msg):
        #save data
        self.vector3_orientation_accuracy_msg = msg
    def vector3_orientation_callback(self, msg):
        #save data
        self.vector3_orientation_msg = msg
        #publish the equivalent interval
        if self.vector3_orientation_accuracy_msg is not None:
            box_stamped = get_box_stamped_from_vectors3(self.vector3_orientation_msg, self.vector3_orientation_accuracy_msg, "orientation")
            self.box_stamped_orientation_pub.publish(box_stamped)
            #self.get_logger().info(f'\nPublished Box: {box_stamped}\n')

    """
    Position
    """
    def vector3_position_accuracy_callback(self, msg):
        #save data
        self.vector3_position_accuracy_msg = msg
    def vector3_position_callback(self, msg):
        #save data
        self.vector3_position_msg = msg
        #publish the equivalent interval
        if self.vector3_position_accuracy_msg is not None:
            box_stamped = get_box_stamped_from_vectors3(self.vector3_position_msg, self.vector3_position_accuracy_msg, "position")
            self.box_stamped_position_pub.publish(box_stamped)
            #self.get_logger().info(f'\nPublished Box: {box_stamped}\n')

    """
    Velocity
    """
    def vector3_velocity_accuracy_callback(self, msg):
        #save data
        self.vector3_velocity_accuracy_msg = msg
    def vector3_velocity_callback(self, msg):
        #save data
        self.vector3_velocity_msg = msg
        #publish the equivalent interval
        if self.vector3_velocity_accuracy_msg is not None:
            box_stamped = get_box_stamped_from_vectors3(self.vector3_velocity_msg, self.vector3_velocity_accuracy_msg, "velocity")
            self.box_stamped_velocity_pub.publish(box_stamped)
            #self.get_logger().info(f'\nPublished Box: {box_stamped}\n')

def get_box_stamped_from_vectors3(vector3_data_msg, vector3_accuracy_msg, box_name):
    acc_x = vector3_accuracy_msg.vector.x/2.0
    acc_y = vector3_accuracy_msg.vector.y/2.0
    acc_z = vector3_accuracy_msg.vector.z/2.0
    intervalx = IntervalMsg(name="Intervalx", start=vector3_data_msg.vector.x-acc_x, end=vector3_data_msg.vector.x+acc_x)
    intervaly = IntervalMsg(name="Intervaly", start=vector3_data_msg.vector.y-acc_y, end=vector3_data_msg.vector.y+acc_y)
    intervalz = IntervalMsg(name="Intervalz", start=vector3_data_msg.vector.z-acc_z, end=vector3_data_msg.vector.z+acc_z)
    box = BoxMsgStamped()
    box.header = vector3_data_msg.header
    box.name = box_name
    box.intervals = [intervalx, intervaly, intervalz]
    return box

def main(args=None):
    rclpy.init(args=args)
    converter_node = ConverterNode()
    rclpy.spin(converter_node)
    converter_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()