FROM debian:11

ENV HOME /root

SHELL ["/bin/bash", "-c"]

RUN apt update && \
    apt -y --no-install-recommends install \
    apt-utils \
    build-essential \
    openssh-server \
    git \
    sudo \
    cmake \
    make \ 
    libxext-dev \
    libxrandr-dev \
    libx11-dev \
    libbsd-dev \
    libssl-dev \
    #para testar geração de janelas com comando *xeyes*
    x11-apps \
    && ldconfig \
    && apt clean

