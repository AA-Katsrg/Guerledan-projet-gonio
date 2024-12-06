#!/bin/bash

echo 'Launching: roscore'

# Start ROS1 and launch roscore in a new tmux session
tmux new-session -d -s runtime_bridge -n roscore "source ${ROS1_INSTALL_PATH}; roscore"
# Add delay before starting the next window
sleep 2  

echo 'Launching: ros_bridge'

# Start ros1_bridge in a named tmux window
tmux new-window -t runtime_bridge -n ros_bridge "source ${ROS1_INSTALL_PATH} && source ${ROS1_WORKSPACE_PATH} && \
source ${ROS2_INSTALL_PATH} && source ${ROS_BRIDGE_PATH} && \
export ROS_MASTER_URI=http://localhost:11311 && \
ros2 run ros1_bridge dynamic_bridge --bridge-all-topics"
# Add delay before starting the next window
#sleep 2 

echo 'Launching: convert_dvl'

# Start the first custom node in a named tmux window
tmux new-window -t runtime_bridge -n convert_dvl "source ${ROS1_INSTALL_PATH} && source ${ROS1_WORKSPACE_PATH} && \
rosrun convert_dvl_to_common convert_dvl_to_common.py"
# Add delay before starting the next window
#sleep 1 

echo 'Launching: convert_sbg'

# Start the second custom node in a named tmux window
tmux new-window -t runtime_bridge -n convert_sbg "source ${ROS1_INSTALL_PATH} && source ${ROS1_WORKSPACE_PATH} && \
rosrun convert_sbg_to_common convert_sbg_to_common.py"
# Add delay before starting the next window
#sleep 1 

echo 'Launching: debug_term'

# Start the debug node in a named tmux window and keep it open
tmux new-window -t runtime_bridge -n debug_term "source ${ROS2_INSTALL_PATH} && ros2 topic list && \
echo '' && \
echo 'ROS BRIDGE launched, to debug, connect through another terminal using:' && \
echo 'docker exec -it ros_bridge_noetic_humble /bin/bash' && \
echo '' && \
echo 'Press Ctrl+b and then w to navigate through windows' && \
read -p 'Press Enter to exit this windows...'"
# Add delay before attaching to the session (optional)
#sleep 1 

# Add delay before attaching to the session (optional)
sleep 1 

# Attach to the tmux session
tmux attach -t runtime_bridge

