## 1) Start from an Image


- Use a initial image with Ubuntu 22.04 and ROS2 Humble installed
- Download the Dockerfile and generate the image:
```
docker build [wanted_image_name]
```

## 2) Start our custom modified container

- (FIRST TIME ONLY), generate a container from the Image:
```
docker run -i -t [image_name] /bin/bash
```
- exit the container (Ctrl+D) and check if container have been created:
```
docker ps -a
```
- Launch the new container that we will modify, before to export it as a new image
```
docker start [container_name_or_id]
docker attach [container_name_or_id]
```
- Connect as a User (if connected as 'root', .bashrc might be ignored):
```
su - rosuser
```

## 3) Prepare Bashrc (Inside the container)

* Delete the ROS2 sourcing (if sourced) (we don't want ROS2 to be sourced automatically)
* Start a new terminal (Or restart Container)

* Define PATHs in bashrc. (workspaces and ROS will not be directly sourced in bashrc, just the paths):
(add following lines to .bashrc)

```
export ROS1_SOURCE=/opt/ros/noetic/setup.bash
export ROS2_SOURCE=/opt/ros/humble/setup.bash 
export ROS1_WORKSPACE=~/ros_noetic_workspace/catkin_ws/devel/setup.bash
export ROS2_WORKSPACE=~/ros_humble_workspace/install/setup.bash
export ROS_Bridge=~/ros_bridge/install/setup.bash
```

## 4) Install/Update ROS2 Humble

* ROS2 humble (apt version, Desktop+Base+DevTools):

https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html

## 5) Install ROS1 Noetic from sources

* Install ROS1 Noetic on Ubuntu 22.04:

https://gist.github.com/Meltwin/fe2c15a5d7e6a8795911907f627255e0

## 6) Install our custom needed ROS1 Packages

* Copy the packages inside 'docker_ros_bridge/docker_ros_packages/ros1/' in '[docker's ROS1 workspace]/src' specified at step 3) in the .bashrc.

* Install them:
```
cd [your ROS1 workspace]
source ${ROS1_SOURCE}
catkin_make --cmake-args -DCMAKE_BUILD_TYPE=Release
```

## 7) Install our custom needed ROS2 Packages

* Copy the packages inside 'docker_ros_bridge/docker_ros_packages/ros2/' in '[docker's ROS2 workspace]/src' specified at step 3) in the .bashrc.

* Install them:
```
cd [your ROS2 workspace]
source ${ROS2_SOURCE}
colcon build
```

## 8) Install ROS Bridge

* Install bridge on ROS2 in the docker's ROS Bridge workspace specified at step 3) in the .bashrc:

https://github.com/ros2/ros1_bridge

```
cd [docker's ROS Bridge workspace]/src
git clone https://github.com/ros2/ros1_bridge.git
cd ..
source ${ROS2_SOURCE} && source ${ROS2_WORKSPACE}
colcon build --cmake-force-configure
rm -r build log install
source ${ROS1_SOURCE} && source ${ROS1_WORKSPACE}
colcon build --cmake-force-configure
```

## 9) Test Installation

Check available detected pairs for the bridge:
```
source ${ROS1_SOURCE} && source ${ROS1_WORKSPACE}
source ${ROS2_SOURCE} && source ${ROS2_WORKSPACE} && source ${ROS_BRIDGE}
export ROS_MASTER_URI=http://localhost:11311
ros2 run ros1_bridge dynamic_bridge --print-pairs
```

Run the Bridge:
```
source ${ROS1_SOURCE} && source ${ROS1_WORKSPACE}
source ${ROS2_SOURCE} && source ${ROS2_WORKSPACE} && source ${ROS_BRIDGE}
export ROS_MASTER_URI=http://127.0.0.1:11311
ros2 run ros1_bridge dynamic_bridge --bridge-all-topics
```

## 10) Export our image

* We can now export this container as an image and share it with other:
```
docker ps -a
docker export -o ros_bridge_noetic_humble.tar [container_name_or_id]
```

## 11) Install the .tar image on another computer
```
docker import ros_bridge_noetic_humble.tar ros_bridge_noetic_humble
```
