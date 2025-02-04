import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/basile/Documents/3a/guerledan/Guerledan-projet-gonio/ros2_ws/install/gonio_python_simu_ros'
