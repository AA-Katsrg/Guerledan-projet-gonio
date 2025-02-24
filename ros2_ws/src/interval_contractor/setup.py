from setuptools import find_packages, setup

package_name = 'interval_contractor'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    py_modules=[
        'interval_contractor.interface_codac',
    ],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='basile',
    maintainer_email='basile.mollard@ensta-bretagne.org',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'interval_contractor_node = interval_contractor.interval_contractor:main',
            'interval_contractor_codac1_node = interval_contractor.interval_contractor_codac1:main',
            'online_interval_contractor_tube_gonio_node = interval_contractor.online_interval_contractor_tube_gonio:main',
            'offline_interval_contractor_tube_gonio_node = interval_contractor.offline_interval_contractor_tube_gonio:main'
            ],
    },
)
