#!/usr/bin/env python

import rospy
from waterlinked_a50_ros_driver.msg import DVL
from geometry_msgs.msg import Vector3Stamped
from geometry_msgs.msg import PointStamped

def callback_dvl(msg):
    # Create the 'velocity' message
    velocity_msg = Vector3Stamped()
    velocity_msg.vector.x = msg.velocity.x  # Extract angle x from the original message
    velocity_msg.vector.y = msg.velocity.y  # Extract angle y from the original message
    velocity_msg.vector.z = msg.velocity.z  # Extract angle z from the original message
    velocity_msg.header = msg.header  # Copy the header from the original message

    # Create the 'altitude' message
    altitude_msg = PointStamped()
    altitude_msg.header = msg.header
    altitude_msg.point.x = msg.altitude  # Use the x field for altitude
    altitude_msg.point.y = 0.0
    altitude_msg.point.z = 0.0

    pub_dvl_velocity.publish(velocity_msg)
    pub_dvl_altitude.publish(altitude_msg)

def listener():
    # Initialize the node
    rospy.init_node('convert_dvl_to_common_node', anonymous=True)

    """
    DVL data
    """
    # Create publisher
    global pub_dvl_velocity
    global pub_dvl_altitude
    pub_dvl_velocity = rospy.Publisher('/dvl/data/velocity', Vector3Stamped, queue_size=10)
    pub_dvl_altitude = rospy.Publisher('/dvl/data/altitude', PointStamped, queue_size=10)
    # Subscribe
    rospy.Subscriber('/dvl/data', DVL, callback_dvl)

    # Keep the node running
    rospy.spin()

if __name__ == '__main__':
    listener()
