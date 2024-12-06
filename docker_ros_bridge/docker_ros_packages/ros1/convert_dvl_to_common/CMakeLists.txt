cmake_minimum_required(VERSION 3.0.2)
project(convert_dvl_to_common)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  rospy
  std_msgs
  waterlinked_a50_ros_driver
)


catkin_package()


# This is to ensure Python files in the scripts folder are executable
catkin_install_python(PROGRAMS
  src/convert_dvl_to_common.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
