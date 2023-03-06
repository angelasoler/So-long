#!/bin/sh

cd /solong/minilibx-linux
./configure
cp mlx.h /usr/local/include
cp libmlx.a /usr/local/lib
cd ..
make
read -p "Nome do mapa:" mapname
./solong maps/$mapname.ber