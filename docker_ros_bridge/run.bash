#!/bin/bash

docker_image=ros_bridge_noetic_humble
cmd="/bin/bash"
#cmd=""

docker run -it --rm --name ros_bridge_noetic_humble \
  -v $(pwd)/app:/home/rosuser/shared \
  ${docker_image} ${cmd}
