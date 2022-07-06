NAME=solong

CC=cc

WARNING_FLAGS=-Wall -Werror -Wextra

X_FLAGS=-lX11 -lXext -lmlx

SRC=so_long.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(X_FLAGS) -L ./ -lft -o $(NAME)

%.o: %.c
	$(CC) -g3 $(FLAGS) -c $< -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o

.PONHY: re fclean clean all
