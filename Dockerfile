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


# CMD ["bash ./configure.sh"]

    #&& /solong/minilibx-linux/configure
    # git clone https://github.com/42Paris/minilibx-linux \
    # cd minilibx-linux \
    # apt-get install libxext-dev libxrandr-dev libx11-dev libbsd-dev libssl-dev \
    # mv minilibx-linux/man/man1 to /usr/local/man/ \
    # mv minilibx-linux/libmlx.a to /usr/local/lib/ \
    # mv minilibx-linux/mlx.h to /usr/local/include/ \

