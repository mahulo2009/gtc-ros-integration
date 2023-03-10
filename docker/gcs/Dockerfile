FROM gcs:halley

#eProsima
RUN yum -y install centos-release-scl 
RUN yum -y install devtoolset-11-gcc devtoolset-11-gcc-c++ cmake3 asio-devel && yum clean all

SHELL [ "/usr/bin/scl", "enable", "devtoolset-11" ]
RUN gcc --version 


RUN mkdir /opt/tinyxml2 && cd /opt/tinyxml2 && git clone https://github.com/leethomason/tinyxml2.git  && mkdir tinyxml2/build && cd tinyxml2/build && cmake3 -DBUILD_SHARED_LIBS=ON .. && make && make install

RUN mkdir /opt/fastdds_ws && cd /opt/fastdds_ws && cd /opt/fastdds_ws && git clone https://github.com/eProsima/foonathan_memory_vendor.git && mkdir foonathan_memory_vendor/build && cd foonathan_memory_vendor/build && cmake3 .. && make && make install
RUN cd /opt/fastdds_ws && git clone https://github.com/eProsima/Fast-CDR.git && mkdir Fast-CDR/build && cd Fast-CDR/build && cmake3 .. && make && make install
RUN cd /opt/fastdds_ws && git clone https://github.com/eProsima/Fast-DDS.git && mkdir Fast-DDS/build && cd Fast-DDS/build && cmake3 .. && make && make install
RUN cd /opt/fastdds_ws && git clone --recursive https://github.com/eProsima/Fast-DDS-Gen.git 


COPY jdk/jdk-17.0.6_linux-x64_bin.rpm /
RUN yum localinstall -y /jdk-17.0.6_linux-x64_bin.rpm && rm -f /jdk-17.0.6_linux-x64_bin.rpm 
RUN wget https://services.gradle.org/distributions/gradle-7.6-bin.zip -P / &&  unzip -d /opt/ /gradle-*.zip && ln -s /opt/gradle-7.6 /opt/gradle && rm /gradle-*.zip

ENV GRADLE_HOME /opt/gradle
ENV PATH ${GRADLE_HOME}/bin:${PATH}

RUN cd /opt/fastdds_ws/Fast-DDS-Gen && gradle assemble

RUN cp -R /opt/gcs/makefiles /work/gcsop/ 

ADD --chown=gcsop:control data/fastdds.mk /work/gcsop/makefiles
ADD --chown=gcsop:control data/gcs.mk /work/gcsop/makefiles

ADD --chown=gcsadm:control  ext/yamlcpp_0.7.0 /opt/gcs/ext/yamlcpp_0.7.0
ADD --chown=gcsadm:control  ext/rabbitmq_c_0.11.0 /opt/gcs/ext/rabbitmq_c_0.11.0/

ADD --chown=gcsadm:control  makefiles/rabbitmqconfig.mk /opt/gcs/makefiles/rabbitmqconfig.mk
ADD --chown=gcsadm:control  makefiles/yamlcppconfig.mk /opt/gcs/makefiles/yamlcppconfig.mk

COPY patches/* /root/

RUN patch /opt/gcs/tools/nrp /root/nrp.patch
RUN patch /opt/gcs/makefiles/gcs.mk /root/gcs.mk.patch
RUN patch /opt/gcs/tools/functions/fnmk.cpp.module /root/fnmk.cpp.module.patch
RUN mkdir -p /work/gcsop/src_c++/gtc/DSL/DAF/ && cp -Rp /opt/gcs/src_c++/gtc/DSL/DAF/ /work/gcsop/src_c++/gtc/DSL/ &&  cd /work/gcsop/src_c++/gtc/DSL/DAF/ && patch DAF.l/CORBAContext.cpp /root/CORBAContext.patch


RUN mkdir -p /work/gcsop/src_java/gtc/AL/Service/MonitorManager && mkdir -p /work/gcsop/src_c++/gtc/DSL && mkdir -p /work/gcsop/src_c++/gtc/DSL/CK
 
ADD --chown=gcsop:control  modules/service /work/gcsop/src_java/gtc/AL/Service/MonitorManager/service
ADD --chown=gcsop:control  modules/DCF /work/gcsop/src_c++/gtc/DSL/CK/DCF
ADD --chown=gcsop:control  modules/Server_Kit /work/gcsop/src_c++/gtc/DSL/Server_Kit
ADD --chown=gcsop:control  modules/DGCSTypesFastDDS /work/gcsop/src_c++/gtc/DGCSTypesFastDDS
ADD --chown=gcsop:control  modules/Server_KitFastDDS /work/gcsop/src_c++/gtc/Server_KitFastDDS
ADD --chown=gcsop:control  modules/InspectorDeviceFastDDS /work/gcsop/src_c++/gtc/InspectorDeviceFastDDS
ADD --chown=gcsop:control  modules/MonitorManagerIntegrationService /work/gcsop/src_c++/gtc/MonitorManagerIntegrationService

CMD ["/sbin/init"]
