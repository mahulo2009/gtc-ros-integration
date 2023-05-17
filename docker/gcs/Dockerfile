FROM mhuertas/gcs:halley

#eProsima
RUN yum -y install centos-release-scl 
RUN yum -y install devtoolset-11-gcc devtoolset-11-gcc-c++ cmake3 asio-devel && yum clean all

RUN echo "scl enable devtoolset-11 bash" >> /root/.bashrc

RUN source scl_source enable devtoolset-11 && \ 
	mkdir /opt/tinyxml2 && cd /opt/tinyxml2 && \
	git clone https://github.com/leethomason/tinyxml2.git  && \ 
	mkdir tinyxml2/build && \ 
	cd tinyxml2/build && \ 
	cmake3 -DBUILD_SHARED_LIBS=ON .. &&  \
	make && \ 
	make install

RUN source scl_source enable devtoolset-11 &&  \ 
	mkdir /opt/fastdds_ws && \ 
	cd /opt/fastdds_ws && \ 
	cd /opt/fastdds_ws && \ 
	git clone https://github.com/eProsima/foonathan_memory_vendor.git && \ 
	mkdir foonathan_memory_vendor/build && \ 
	cd foonathan_memory_vendor/build && \ 
	cmake3 .. && \ 
	make && \
	make install

RUN source scl_source enable devtoolset-11 &&  \ 
	cd /opt/fastdds_ws && \ 
	git clone https://github.com/eProsima/Fast-CDR.git && \ 
	mkdir Fast-CDR/build && \ 
	cd Fast-CDR/build && \ 
	cmake3 .. && \ 
	make && \ 
	make install

RUN source scl_source enable devtoolset-11 && \
	cd /opt/fastdds_ws && \
	git clone https://github.com/eProsima/Fast-DDS.git && \ 
	mkdir Fast-DDS/build && \ 
	cd Fast-DDS/build && \
 	cmake3 .. && \	
	make && \ 
	make install

RUN cd /opt/fastdds_ws && git clone --recursive https://github.com/eProsima/Fast-DDS-Gen.git 

RUN wget https://download.oracle.com/java/17/archive/jdk-17.0.6_linux-x64_bin.rpm
RUN yum localinstall -y /jdk-17.0.6_linux-x64_bin.rpm && rm -f /jdk-17.0.6_linux-x64_bin.rpm 

RUN wget https://services.gradle.org/distributions/gradle-7.6-bin.zip -P / &&  unzip -d /opt/ /gradle-*.zip && ln -s /opt/gradle-7.6 /opt/gradle && rm /gradle-*.zip

ENV GRADLE_HOME /opt/gradle
ENV PATH ${GRADLE_HOME}/bin:${PATH}

RUN cd /opt/fastdds_ws/Fast-DDS-Gen && gradle assemble

RUN cp -R /opt/gcs/makefiles /work/gcsop/ 

ADD --chown=gcsop:control data/fastdds.mk /work/gcsop/makefiles
ADD --chown=gcsop:control data/gcs.mk /work/gcsop/makefiles

COPY patches/* /tmp/

RUN patch /opt/gcs/tools/nrp /tmp/nrp.patch
RUN mkdir -p /work/gcsop/src_c++/gtc/DSL/DAF/ && cp -Rp /opt/gcs/src_c++/gtc/DSL/DAF/ /work/gcsop/src_c++/gtc/DSL/ &&  cd /work/gcsop/src_c++/gtc/DSL/DAF/ && patch DAF.l/CORBAContext.cpp /tmp/CORBAContext.patch

RUN git clone https://***:***@github.com/mahulo2009/DGCSTypesFastDDS.git /work/gcsop/src_c++/gtc/DGCSTypesFastDDS
RUN git clone https://***:***@github.com/mahulo2009/Server_KitFastDDS.git /work/gcsop/src_c++/gtc/Server_KitFastDDS
RUN git clone https://***:***@github.com/mahulo2009/InspectorDeviceFastDDS.git /work/gcsop/src_c++/gtc/InspectorDeviceFastDDS

RUN chown -R gcsop:control /work/gcsop

RUN sed -i '/scl/d' /root/.bashrc 

CMD ["/sbin/init"]
