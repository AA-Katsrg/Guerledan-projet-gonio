from setuptools import find_packages
from setuptools import setup

setup(
    name='interval_analysis_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('interval_analysis_interfaces', 'interval_analysis_interfaces.*')),
)
