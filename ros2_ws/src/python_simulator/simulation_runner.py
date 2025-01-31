import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
from BoxStamped.msg import Box
from Interval.msg import Interval
from datetime import datetime
from simu import Simulation
from boat import Boat
from buoy import Buoy
from calcul_tools import *
from draw import *


class PositionPublisher(Node):
    def __init__(self, threshold=0.1):  # Add threshold as a parameter
        super().__init__('position_publisher')
        self.publisher_ = self.create_publisher(Box, '/it/position', 10)
        self.threshold = threshold  # Store threshold value

    def publish_position(self, x, y, z=0.0):
        # Create intervals using the threshold
        interval_x = Interval(name="x", start=x - self.threshold, end=x + self.threshold)
        interval_y = Interval(name="y", start=y - self.threshold, end=y + self.threshold)
        interval_z = Interval(name="z", start=z, end=z)  # Fixed at 0 for 2D

        # Populate Box message
        msg = Box()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.name = "USV position"
        msg.intervals = [interval_x, interval_y, interval_z]

        self.publisher_.publish(msg)
        self.get_logger().info(f'Published position: x=[{x-self.threshold}, {x+self.threshold}], '
                               f'y=[{y-self.threshold}, {y+self.threshold}], z=[{z}]')


class SimulationRunner:
    def __init__(self, threshold=0.1):  # Threshold for intervals
        self.s = 8
        self.dt = 0.1
        self.k = 0.5
        self.Ɛ = 2
        self.num_steps = 1000
        self.record_data = False
        self.position_publisher = PositionPublisher(threshold)  # Pass threshold

    def initialize_sea_objects(self):
        sea_objects = []
        sea_objects.append(Boat(222, -6, 2, 1.5, 0.25, 4, 1.75))
        sea_objects.append(Buoy(333, 0, 2, 0, 1, 0, 0))
        return sea_objects

    def run(self):
        rclpy.init()  # Initialize ROS2
        sea_objects = self.initialize_sea_objects()
        simulation = Simulation(sea_objects, self.dt, self.k)
        fig, ax = init_figure(-self.s, self.s, -self.s, self.s)

        for step in range(self.num_steps):
            # Clear the plot and update positions
            simulation.run(self.record_data, 1, ax, self.Ɛ, self.s)

            # Publish position for the first boat --> check in initialize_sea_objects
            # Adapt depedning on the chosen configuration, but we should always have one boat in our project
            boat = sea_objects[0]  # Assuming the first object is the boat
            self.position_publisher.publish_position(boat.x, boat.y, z=0.0)

        rclpy.shutdown()  # Shutdown ROS2


if __name__ == "__main__":
    runner = SimulationRunner(threshold=0.2)  # Set threshold value
    runner.run()
