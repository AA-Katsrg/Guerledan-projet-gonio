from setuptools import find_packages, setup

package_name = 'gonio_python_simu_ros'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    py_modules=[
        'gonio_python_simu_ros.simu',
        'gonio_python_simu_ros.boat',
        'gonio_python_simu_ros.buoy',
        'gonio_python_simu_ros.calcul_tools',
        'gonio_python_simu_ros.draw',
        'gonio_python_simu_ros.potential_fields',
        'gonio_python_simu_ros.sea_object',
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='reximini',
    maintainer_email='onoel2050@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'gonio_python_simu_ros_node = gonio_python_simu_ros.gonio_python_simu_ros_node:main'
        ],
    },
)
