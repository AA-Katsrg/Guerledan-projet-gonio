#!/usr/bin/env python

import rospy
from sbg_driver.msg import SbgEkfEuler
from sbg_driver.msg import SbgEkfNav
from sbg_driver.msg import SbgGpsHdt
from sbg_driver.msg import SbgGpsPos
from geometry_msgs.msg import Vector3Stamped
from geometry_msgs.msg import PointStamped

def callback_ekf_euler(msg):
    # Create the 'angle' message
    angle_msg = Vector3Stamped()
    angle_msg.vector.x = msg.angle.x  # Extract angle x from the original message
    angle_msg.vector.y = msg.angle.y  # Extract angle y from the original message
    angle_msg.vector.z = msg.angle.z  # Extract angle z from the original message
    angle_msg.header = msg.header  # Copy the header from the original message

    # Create the 'accuracy' message
    accuracy_msg = Vector3Stamped()
    accuracy_msg.vector.x = msg.accuracy.x  # Extract accuracy x from the original message
    accuracy_msg.vector.y = msg.accuracy.y  # Extract accuracy y from the original message
    accuracy_msg.vector.z = msg.accuracy.z  # Extract accuracy z from the original message
    accuracy_msg.header = msg.header  # Copy the header from the original message

    #Publish
    pub_ekf_euler_angle.publish(angle_msg)
    pub_ekf_euler_accuracy.publish(accuracy_msg)

def callback_ekf_nav(msg):
    # Create the 'velocity' message
    velocity_msg = Vector3Stamped()
    velocity_msg.vector.x = msg.velocity.x  # Extract velocity x from the original message
    velocity_msg.vector.y = msg.velocity.y  # Extract velocity y from the original message
    velocity_msg.vector.z = msg.velocity.z  # Extract velocity z from the original message
    velocity_msg.header = msg.header  # Copy the header from the original message

    # Create the 'velocity_accuracy' message
    velocity_accuracy_msg = Vector3Stamped()
    velocity_accuracy_msg.vector.x = msg.velocity_accuracy.x  # Extract velocity accuracy x
    velocity_accuracy_msg.vector.y = msg.velocity_accuracy.y  # Extract velocity accuracy y
    velocity_accuracy_msg.vector.z = msg.velocity_accuracy.z  # Extract velocity accuracy z
    velocity_accuracy_msg.header = msg.header  # Copy the header from the original message

    # Create the 'position' message
    position_msg = Vector3Stamped()
    position_msg.vector.x = msg.position.x  # Extract position x
    position_msg.vector.y = msg.position.y  # Extract position y
    position_msg.vector.z = msg.position.z  # Extract position z
    position_msg.header = msg.header  # Copy the header from the original message

    # Create the 'position_accuracy' message
    position_accuracy_msg = Vector3Stamped()
    position_accuracy_msg.vector.x = msg.position_accuracy.x  # Extract position accuracy x
    position_accuracy_msg.vector.y = msg.position_accuracy.y  # Extract position accuracy y
    position_accuracy_msg.vector.z = msg.position_accuracy.z  # Extract position accuracy z
    position_accuracy_msg.header = msg.header  # Copy the header from the original message

    # Publish
    pub_ekf_nav_vel.publish(velocity_msg)
    pub_ekf_nav_vel_acc.publish(velocity_accuracy_msg)
    pub_ekf_nav_pos.publish(position_msg)
    pub_ekf_nav_pos_acc.publish(position_accuracy_msg)

def callback_gps_hdt(msg):
    # Create and publish the 'pitch' message
    pitch_msg = PointStamped()
    pitch_msg.header = msg.header
    pitch_msg.point.x = msg.pitch  # Use the x field for pitch
    pitch_msg.point.y = 0.0        # Not used
    pitch_msg.point.z = 0.0        # Not used
    pub_gps_hdt_pitch.publish(pitch_msg)

    # Create and publish the 'pitch_accuracy' message
    pitch_acc_msg = PointStamped()
    pitch_acc_msg.header = msg.header
    pitch_acc_msg.point.x = msg.pitch_acc  # Use the x field for pitch accuracy
    pitch_acc_msg.point.y = 0.0
    pitch_acc_msg.point.z = 0.0
    pub_gps_hdt_pitch_acc.publish(pitch_acc_msg)

    # Create and publish the 'true_heading' message
    heading_msg = PointStamped()
    heading_msg.header = msg.header
    heading_msg.point.x = msg.true_heading  # Use the x field for true heading
    heading_msg.point.y = 0.0
    heading_msg.point.z = 0.0
    pub_gps_hdt_heading.publish(heading_msg)

    # Create and publish the 'true_heading_accuracy' message
    heading_acc_msg = PointStamped()
    heading_acc_msg.header = msg.header
    heading_acc_msg.point.x = msg.true_heading_acc  # Use the x field for true heading accuracy
    heading_acc_msg.point.y = 0.0
    heading_acc_msg.point.z = 0.0
    pub_gps_hdt_heading_acc.publish(heading_acc_msg)

def callback_gps_pos(msg):
    # Create the 'position' message
    position_msg = Vector3Stamped()
    position_msg.header = msg.header
    position_msg.vector.x = msg.position.x  # Extract position x from the message
    position_msg.vector.y = msg.position.y  # Extract position y from the message
    position_msg.vector.z = msg.position.z  # Extract position z from the message

    # Create the 'position_accuracy' message
    position_acc_msg = Vector3Stamped()
    position_acc_msg.header = msg.header
    position_acc_msg.vector.x = msg.position_accuracy.x  # Extract accuracy x from the message
    position_acc_msg.vector.y = msg.position_accuracy.y  # Extract accuracy y from the message
    position_acc_msg.vector.z = msg.position_accuracy.z  # Extract accuracy z from the message

    # Publish the messages
    pub_gps_pos_position.publish(position_msg)
    pub_gps_pos_position_acc.publish(position_acc_msg)

def listener():
    # Initialize the node
    rospy.init_node('convert_sbg_to_common_node', anonymous=True)

    """
    ekf_euler: Computed orientation using Euler angles.
    """
    # Create publishers
    global pub_ekf_euler_angle
    global pub_ekf_euler_accuracy
    pub_ekf_euler_angle = rospy.Publisher('/sbg/ekf_euler/angle', Vector3Stamped, queue_size=10)
    pub_ekf_euler_accuracy = rospy.Publisher('/sbg/ekf_euler/accuracy', Vector3Stamped, queue_size=10)
    # Subscribe
    rospy.Subscriber('/sbg/ekf_euler', SbgEkfEuler, callback_ekf_euler)

    """
    ekf_nav: Computed navigation data.
    """
    # Create publishers
    global pub_ekf_nav_vel
    global pub_ekf_nav_vel_acc
    global pub_ekf_nav_pos
    global pub_ekf_nav_pos_acc
    pub_ekf_nav_vel = rospy.Publisher('/sbg/ekf_euler/velocity', Vector3Stamped, queue_size=10)
    pub_ekf_nav_vel_acc = rospy.Publisher('/sbg/ekf_euler/velocity_accuracy', Vector3Stamped, queue_size=10)
    pub_ekf_nav_pos = rospy.Publisher('/sbg/ekf_euler/position', Vector3Stamped, queue_size=10)
    pub_ekf_nav_pos_acc = rospy.Publisher('/sbg/ekf_euler/position_accuracy', Vector3Stamped, queue_size=10)
    # Subscribe
    rospy.Subscriber('/sbg/ekf_nav', SbgEkfNav, callback_ekf_nav)

    """
    gos_hdt: GPS true heading from dual antenna system.
    """
    # Create publishers
    global pub_gps_hdt_pitch
    global pub_gps_hdt_pitch_acc
    global pub_gps_hdt_heading
    global pub_gps_hdt_heading_acc
    pub_gps_hdt_pitch = rospy.Publisher('/sbg/gps_hdt/pitch', PointStamped, queue_size=10)
    pub_gps_hdt_pitch_acc = rospy.Publisher('/sbg/gps_hdt/pitch_acc', PointStamped, queue_size=10)
    pub_gps_hdt_heading = rospy.Publisher('/sbg/gps_hdt/true_heading', PointStamped, queue_size=10)
    pub_gps_hdt_heading_acc = rospy.Publisher('/sbg/gps_hdt/true_heading_acc', PointStamped, queue_size=10)
    # Subscribe
    rospy.Subscriber('/sbg/gps_hdt', SbgGpsHdt, callback_gps_hdt)

    """
    gos_pos: GPS positions from GPS receiver.
    """
    # Create publishers
    global pub_gps_pos_position
    global pub_gps_pos_position_acc
    pub_gps_pos_position = rospy.Publisher('/sbg/gps_pos/position', Vector3Stamped, queue_size=10)
    pub_gps_pos_position_acc = rospy.Publisher('/sbg/gps_pos/position_accuracy', Vector3Stamped, queue_size=10)
    # Subscribe
    rospy.Subscriber('/sbg/gps_pos', SbgGpsPos, callback_gps_pos)

    # Keep the node running
    rospy.spin()

if __name__ == '__main__':
    listener()
