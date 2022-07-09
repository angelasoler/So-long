NAME=solong

CCw=cc -Wall -Werror -Wextra


X_FLAGS=-lX11 -lXext -lmlx

SRC=so_long.c so_long_utils.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CCw) $(OBJ) $(X_FLAGS) -L ./ -lft -o $(NAME)

%.o: %.c
	$(CCw) -g3 $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PONHY: re fclean clean all
