#!/bin/bash

docker_image=ros_bridge_noetic_humble
#cmd="/bin/bash"
cmd=""

docker run -it --rm --name ros_bridge_docker \
  -v $(pwd)/app:/home/rosuser/app \
  ${docker_image} ${cmd}
