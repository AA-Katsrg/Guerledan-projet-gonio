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
import math


class USVPublisher(Node):
    def __init__(self, threshold=0.1):
        super().__init__('usv_publisher')
        self.position_publisher = self.create_publisher(Box, '/it/position', 10)
        self.velocity_publisher = self.create_publisher(Box, '/it/velocity', 10)
        self.threshold = threshold

    def publish_position(self, x, y, z=0.0):
        # Create intervals for position
        interval_x = Interval(name="x", start=x - self.threshold, end=x + self.threshold)
        interval_y = Interval(name="y", start=y - self.threshold, end=y + self.threshold)
        interval_z = Interval(name="z", start=z, end=z)

        msg = Box()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.name = "USV position"
        msg.intervals = [interval_x, interval_y, interval_z]

        self.position_publisher.publish(msg)
        self.get_logger().info(f'Published position: x=[{x-self.threshold}, {x+self.threshold}], '
                               f'y=[{y-self.threshold}, {y+self.threshold}], z=[{z}]')

    def publish_velocity(self, speed, theta):
        vx = speed * math.cos(theta)
        vy = speed * math.sin(theta)
        vz = 0.0  # Fixed at 0 for 2D

        # Create intervals for velocity
        interval_vx = Interval(name="vx", start=vx - self.threshold, end=vx + self.threshold)
        interval_vy = Interval(name="vy", start=vy - self.threshold, end=vy + self.threshold)
        interval_vz = Interval(name="vz", start=vz, end=vz)

        msg = Box()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "map"
        msg.name = "USV velocity"
        msg.intervals = [interval_vx, interval_vy, interval_vz]

        self.velocity_publisher.publish(msg)
        self.get_logger().info(f'Published velocity: vx=[{vx-self.threshold}, {vx+self.threshold}], '
                               f'vy=[{vy-self.threshold}, {vy+self.threshold}], vz=[{vz}]')


class SimulationRunner:
    def __init__(self, threshold=0.1):
        self.s = 8
        self.dt = 0.1
        self.k = 0.5
        self.Ɛ = 2
        self.num_steps = 1000
        self.record_data = False
        self.usv_publisher = USVPublisher(threshold)

    def initialize_sea_objects(self):
        sea_objects = []
        sea_objects.append(Boat(222, -6, 2, 1.5, 0.25, 4, 1.75))
        sea_objects.append(Buoy(333, 0, 2, 0, 1, 0, 0))
        return sea_objects

    def run(self):
        rclpy.init()
        sea_objects = self.initialize_sea_objects()
        simulation = Simulation(sea_objects, self.dt, self.k)
        fig, ax = init_figure(-self.s, self.s, -self.s, self.s)

        for step in range(self.num_steps):
            simulation.run(self.record_data, 1, ax, self.Ɛ, self.s)

            # Publish position for the first boat --> check in initialize_sea_objects
            # Adapt depending on the chosen configuration, but we should always have one boat in our project
            boat = sea_objects[0]   # First object should be the boat
            self.usv_publisher.publish_position(boat.x, boat.y, z=0.0)
            self.usv_publisher.publish_velocity(boat.v, boat.theta)

        rclpy.shutdown()


if __name__ == "__main__":
    runner = SimulationRunner(threshold=0.2)
    runner.run()
