#!/bin/bash

docker_image=ros_bridge_noetic_humble
cmd="/bin/bash"
#cmd=""

#This one allow to have the bridge working, but we don't see topics on our computer's network
#docker run -it --rm --name ros_bridge_noetic_humble \
#  -v $(pwd)/app:/home/rosuser/shared \
#  ${docker_image} ${cmd}
  
#This one allow to see the topics on our computers networks, but the bridge is not converting the ROS1 topics
docker run -it --rm --net host --name ros_bridge_noetic_humble \
  -e ROS_LOCALHOST_ONLY=0 \
  -v $(pwd)/app:/home/rosuser/shared \
  -v /dev/shm:/dev/shm \
  ${docker_image} ${cmd}
