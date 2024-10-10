# Use Ubuntu 22.04 as the base image
FROM ubuntu:22.04

# Set environment variables
ENV ROS_VERSION=2
ENV ROS_DISTRO=humble
ENV ROS_PYTHON_VERSION=3
ENV PYTHONUNBUFFERED=1
ENV QT_QPA_PLATFORM_PLUGIN_PATH=/usr/lib/x86_64-linux-gnu/qt5/plugins/platforms

# Set locale and timezone
ENV TZ=Europe/Paris
RUN apt-get update && apt-get install -y \
    locales \
    && locale-gen fr_FR fr_FR.UTF-8 \
    && update-locale LC_ALL=fr_FR.UTF-8 LANG=fr_FR.UTF-8 \
    && ln -snf /usr/share/zoneinfo/$TZ /etc/localtime \
    && echo $TZ > /etc/timezones

# Install system dependencies
RUN apt-get update && apt-get install -y \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common \
    build-essential \
    cmake \
    libgl1-mesa-glx \
    libglib2.0-0 \
    libx11-6 \
    libxext6 \
    libsm6 \
    libxrender1 \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    python3-pip \
    nano \
    v4l-utils 

# Switch to user
USER user
WORKDIR /home/user

# Set the working directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Make port 80 available to the world outside this container
EXPOSE 80


