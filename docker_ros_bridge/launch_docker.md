
docker attach [container]
docker start [container]
su - rosuser

#run the bridge with tmux
./start_runtime_bridge.sh

#This will start 2 tmux sessions, to switch
1) Press Ctrl+b
2) Press the number of the session you want to connect to (0, 1, 2 ...)
Or press Ctrl+b and then 'w' to have list of current session