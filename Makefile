NAME=solong

CCW=gcc -Wall -Werror -Wextra

X_FLAGS=-lX11 -lXext -lmlx

MAKE_LIBFT=libft.a

SRC=so_long.c \
	so_long_window_utils.c \
	so_long_events.c \
	so_long_map_rules.c

OBJ = $(SRC:.c=.o)

PWD=$(shell pwd)

BUILD=docker build -t ${NAME} .

RUN=docker run -it --rm --privileged --name=${NAME} \
	--mount type=bind,source=${PWD},target=/solong \
	-e DISPLAY=${DISPLAY} -e PATH=${PATH}:/solong -v /tmp/.X11-unix:/tmp/.X11-unix:ro \
	${NAME} configure.sh

EXEC=docker exec -ti ${NAME} bash

all: $(NAME) clean

$(NAME): $(OBJ) $(MAKE_LIBFT) $(MAKE_MINILIBX)
	$(CCW) $(OBJ) $(X_FLAGS) -L ./ -lft -lmlx -lX11 -lXext -o $(NAME)

%.o: %.c
	$(CCW) -c $< -o $@

$(MAKE_LIBFT):
	make -C libft/

$(MAKE_MINILIBX):
	make -C minilibx-linux
	cp minilibx-linux/mlx.h /usr/local/lib
	cp minilibx-linux/minilibx.a /usr/local/include

re: fclean all

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

clean:
	rm -rf *.o

run:
	${BUILD}
	${RUN}

start: 
	docker start ${NAME}
	$(EXEC)

.PONHY: re fclean clean all
