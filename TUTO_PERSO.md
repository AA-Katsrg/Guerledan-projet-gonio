## UNBUNTU Tips:

### Identify USB connected devices
See plugs/Unplugs logs
```
dmesg | grep tty
```

See Devices
```
lsusb
lsusb -v
```

See IDs of connected devices
```
ls /dev/serial/by-id/
```

See Current used USB port
```
ls /dev/ttyUSB*
```

### Add rules for connected devices
create a file XXcustom-rules.rules, with XX a number, then add it in '/etc/udev/rules.d' and add rules in it.
Example with defining a custom ID for a device:
```
KERNELS=="1-4.1", ATTRS{idVendor}=="10c4", ATTRS{idProduct}=="ea60", SYMLINK+="usbrs485r"
```
This detect when a device with these IDVendor, IDproduct and kernels is connected to the computer and create a symlink in /dev to access it.
So no need to depend on 'ttyUSB0' that can be attribuated differently by the kernel.

Get KERNELS Informations with:
```
udevadm info -q path -n /dev/[device_id]
```

Get idVendor and productVendor with 'lsusb', ID xxxx:xxxx = (vendor:product)
Put wanted name for the device.

### Change lid action
https://fostips.com/lid-close-action-ubuntu-21-04-laptop/

### Use AppImage in Linux
https://itsfoss.com/use-appimage-linux/

### Tool to manage packages:

https://askubuntu.com/questions/160897/how-do-i-search-for-available-packages-from-the-command-line

```
sudo apt-get install synaptic
synaptic
```

### Reload a terminal without closing it:
```
bash --login
```

### Open access to USB so that program don't need sudo mode
Give user permissions to use ports
```
sudo usermod -aG dialout $USER
```

Open port to all user:
```
sudo chmod a+rw /dev/ttyUSB*
```

## Git tuto:
Clone specific branch:
```
git clone --branch <branchname> <remote-repo-url>
```

Clone a git with all its submodules:
```
git clone --recurse-submodules -j8 <remote-repo-url>
```

add submodules:
```
git submodule add <url> workspace_ros2/src/directory_name
```

Or with specific branch:
```
git submodule add -b <branch name> <url> workspace_ros2/src/directory_name
```

delete submodules:
1)Delete the submodule entry
2)Remove the submodule from the Git configuration
3)Delete the submodule files
4)Remove the submodule section from the .gitmodules file

```
git submodule deinit -f path/to/submodule
git rm --cached path/to/submodule
rm -rf path/to/submodule
```

remove added files ready to commit:
```
git rm --cached <directory>
```

## SSH:
connection:
```
ssh user@xxx.xxx.xxx.xx
```

connection with graphical possibility:
```
ssh -X user@xxx.xxx.xxx.xx
```
example, open an app:
```
gedit
```
visual code:
```
code . 
```
settings
```
gnome-control-center
```
connections editor, connect, modif...
```
sudo nmtui
```
connection priorities
```
sudo nm-connection-editor
```
show connection priorities
```
nmcli -f autoconnect-priority,name c 
```
edit connection prority of a connection
```
nmcli connection modify "Caffe Ubuntu" connection.autoconnect-priority 10
```

Scan ip reseau:
- ipscan (installer angry ip scanner)
- ou nmap

## WI-FI adapter Unclaimed
install backports:
https://installati.one/install-backport-iwlwifi-dkms-ubuntu-22-04/

If connection slow, turn off power saving for wireless:
```
Open '/etc/NetworkManager/conf.d/default-wifi-powersave-on.conf' and set wifi.powersave = 2
```

Wiki AIST Jetson:
https://github.com/isri-aist/wiki/blob/master/hrp4cr-hardware/jetson_setup.md

Connection Speed test:
* Start the server on one PC using $ iperf3 -s
* On the client PC, $ iperf3 -c [server ip addr] -b 0 -l 16K -t 60 -i 1

## ROS TUTO:

Installation:
https://docs.ros.org/en/foxy/Installation/Ubuntu-Install-Debians.html

Topic vs Services vs Actions:
https://automaticaddison.com/topics-vs-services-vs-actions-in-ros2-based-projects/

Synchronize time between host machine and remote (chrony):
https://robofoundry.medium.com/how-to-sync-time-between-robot-and-host-machine-for-ros2-ecbcff8aadc4

### Install specific package
```
sudo apt-get install ros-<ros_version>-PACKAGE
```
<ros_version> = foxy, noetic...

### Using colcon to build packages
https://docs.ros.org/en/foxy/Tutorials/Beginner-Client-Libraries/Colcon-Tutorial.html

Compile or create project: create copy of files and executables in /install:
```
colcon build
```
Use links to reference files, so when files (others than .cpp) in /src are modified, no need to compile again for taking effect:
```
colcon build --symlink-install
```


Creation of package using ament_cmake as build type, and some dependencies: 
```
ros2 pkg create --build-type ament_cmake pkg_name --dependencies rclcpp std_msgs 
```
Build types: 
- ament_cmake (for C++, use Cmake)
- ament_python (for Python)

Test if all packages can access their dependencies:
```
colcon test
```
(don't forget to source workspace)

Multiple ROS version in terminal problem:
- Source only one setup.bash ROS version in .bashrc
- If 2 ros version are still detected when launching terminals, could be because of workspace's setup.bash's file that source the two ROS, to solve the problem: delete the directories 'install', 'build' and do 'colcon build' to reconsrtuct the workspace with the good ROS sourced.

### Simple commands
See list of installed packages:
```
ros2 pkg list
```

See list of topics:
```
ros2 topic list
```

See info on topic:
```
ros2 topic info <topic_name>
```

See type of topic:
```
ros2 topic type <topic_name>
```

Subscribe to a topic:
```
ros2 topic echo <topic_name>
```

Publish a topic to another one from terminal:
```
ros2 topic pub -r <frequency(Hz)> <topic_type> "{data:...}"
```
```
ros2 topic pub <nb_repetitions> <topic_type> "{data:...}"
```

Run an installed node:
```
ros2 run <package_name> <node_name>
```

Run an installed node with parameters:
```
ros2 run my_package node_executable --ros-args -p some_int:=42 -p "a_string:=Hello world" -p "some_lists.some_integers:=[1, 2, 3, 4]" -p "some_lists.some_doubles:=[3.14, 2.718]"
```

### ROS Launch

Where to put launch file:
```
your_ros2_workspace/
|-- build/
|-- install/
|-- src/
|   |-- your_package/
|       |-- launch/
|           |-- my_launch_file.py  //HERE
|       |-- CMakeLists.txt
|       |-- package.xml
|       |-- ...
```

Command to start nodes:
```
ros2 launch your_package my_launch_file.py
```

Install launch files with CmakeList:
```
# Install launch files
install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)
```

Launch Node classic template:
```
import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='your_package',
            executable='node_1_executable',
            name='node_1',
            output='screen',
            emulate_tty=True,
            prefix=['sudo'],
        ),
        Node(
            package='your_package',
            executable='node_2_executable',
            name='node_2',
            output='screen',
            emulate_tty=True,
            prefix=['sudo'],
        ),
        # Add more nodes as needed
    ])
```

Launch Node template to open nodes in other terminal (Possible to mix templates)
```
import launch
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        launch.actions.ExecuteProcess(
            cmd=['xterm', '-fn', 'xft:DejaVu Sans Mono:size=12', '-e', 'ros2', 'run', 'pakage_name', 'node_name'],
            output='screen',
        ),
        launch.actions.ExecuteProcess(
            cmd=['xterm', '-fn', 'xft:DejaVu Sans Mono:size=12', '-e', 'ros2', 'run', 'pakage_name', 'node_name'],
            output='screen',
        ),
    ])
```

### Managing dependencies of packages

General informations:
https://docs.ros.org/en/foxy/Tutorials/Intermediate/Rosdep.html

ament_cmake tutorial:
https://docs.ros.org/en/foxy/How-To-Guides/Ament-CMake-Documentation.html?highlight=dependencies

add a package:
In XML file: ```<depend>"package_name"</depend>```
In Cmakelist file: ```find_package(package_name REQUIRED)```

### configure VScode for ROS2
https://www.youtube.com/watch?v=hf76VY0a5Fk

Launch VS_code from workspace/src directory:
```
code .
```

### ROS Standards REPs

REP 105 - Coordinate Frames for Mobile Platforms (https://www.ros.org/reps/rep-0105.html)
REP 103 - Standard Units of Measure and Coordinate Conventions (https://www.ros.org/reps/rep-0103.html)

## URDF/SDF tuto and docs
http://sdformat.org/spec

