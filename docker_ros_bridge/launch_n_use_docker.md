## 1) Add/delete shared files
* Runtime shared files are inside the directory 'app'
* Put any necessary files like Rosbags you would want to replay inside it

## 2) Start the Docker
```
bash run.bash
```

or if running, connect to it:
```
docker exec -it ros_bridge_noetic_humble /bin/bash
```

## 3) Login as User if not logged in (/root)
```
su - rosuser
```

## 4) Run our custom shared bash files (inside docker)
* To simply run the bridge that converts ROS1 Noetic messages to ROS2 Humble ones.
```
bash shared/start_runtime_bridge.sh
```
* To Replay a ROS1 bag + run the bridge that converts ROS1 Noetic messages to ROS2 Humble ones.
```
bash shared/start_replay_bridge.sh shared/[path_or_name_rosbag]
```

## 5) Switch the tmux terminals if needed
* 1) Press Ctrl+b (nothing should happen)
* 2) Press the number of the session you want to connect to (0, 1, 2 ...)
* Or press Ctrl+b and then 'w' to have list of current session and seect the wanted one
