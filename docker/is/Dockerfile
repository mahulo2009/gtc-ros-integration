FROM osrf/ros:foxy-desktop

# eProsima Integration Service dependencies
RUN apt update && apt install -y libyaml-cpp-dev libboost-program-options-dev && rm -rf /var/lib/apt/lists/*

# eProsima Integration Service 
RUN mkdir /root/is-workspace && cd /root/is-workspace && git clone https://github.com/eProsima/Integration-Service.git src/Integration-Service --recursive

# eProsima Integration Service handles
RUN cd /root/is-workspace && git clone https://github.com/eProsima/ROS2-SH.git src/ROS2-SH

RUN cd /root/is-workspace && git clone https://github.com/eProsima/FastDDS-SH.git src/FastDDS-SH

RUN . /opt/ros/${ROS_DISTRO}/setup.sh && cd /root/is-workspace && colcon build

# Run
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source /root/is-workspace/install/setup.bash && integration-service /root/is-workspace/conf/config.yaml"]
