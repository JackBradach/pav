FROM jbradach/toolchains:latest
MAINTAINER Jack Bradach <jack@bradach.net>

RUN DEBIAN_FRONTEND=noninteractive apt-get update \
    && apt-get install -y \
        freeglut3-dev \
        libglew-dev \
        libplplot-dev \
        libsdl2-dev \
        libsdl2-mixer-dev \
        libsdl2-ttf-dev \
        libxmu-dev \
        libxi-dev \
        zlib1g-dev
