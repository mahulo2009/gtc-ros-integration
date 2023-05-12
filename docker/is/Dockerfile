FROM osrf/ros:foxy-desktop

# eProsima Integration Service dependencies
RUN apt update && apt install -y libyaml-cpp-dev libboost-program-options-dev && rm -rf /var/lib/apt/lists/*

RUN useradd gcsop
RUN mkdir /is-workspace && chown gcsop:gcsop /is-workspace 
RUN mkdir /home/gcsop && chown -R gcsop:gcsop /home/gcsop
USER gcsop 

RUN cd /is-workspace && git clone https://github.com/eProsima/Integration-Service.git src/Integration-Service --recursive


# eProsima Integration Service handles
RUN cd /is-workspace && git clone https://github.com/eProsima/ROS2-SH.git src/ROS2-SH

RUN cd /is-workspace && git clone https://github.com/eProsima/FastDDS-SH.git src/FastDDS-SH

RUN . /opt/ros/${ROS_DISTRO}/setup.sh && cd /is-workspace && colcon build

ADD conf/config.yaml /is-workspace/conf/config.yaml 

# Run
ENTRYPOINT ["/bin/bash", "-c", "source /opt/ros/${ROS_DISTRO}/setup.bash && source /is-workspace/install/setup.bash && integration-service /is-workspace/conf/config.yaml"]
