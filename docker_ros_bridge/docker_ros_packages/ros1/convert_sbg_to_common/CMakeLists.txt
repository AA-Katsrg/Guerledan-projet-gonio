cmake_minimum_required(VERSION 3.0.2)
project(convert_sbg_to_common)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sbg_driver
  std_msgs
)

catkin_package()


# This is to ensure Python files in the scripts folder are executable
catkin_install_python(PROGRAMS
  src/convert_sbg_to_common.py
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
