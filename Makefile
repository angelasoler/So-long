NAME = so_long

CCW = cc -Wall -Werror -Wextra

X_FLAGS = -lX11 -lXext -lmlx

MAKE_LIBFT = libft.a

SRC =	so_long.c \
		so_long_window_utils.c \
		so_long_events.c \
		so_long_map_rules.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MAKE_LIBFT)
	$(CCW) $(OBJ) $(X_FLAGS) -L ./ -lft -o $(NAME)

%.o: %.c
	$(CCW) $(FLAGS) -c $< -o $@

$(MAKE_LIBFT):
	make -C libft/

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PONHY: re fclean clean all
