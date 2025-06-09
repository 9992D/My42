CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

NAME = fractol

CC = gcc

MLX_DIR = ./mlx
INCLUDES = -I$(MLX_DIR)

SRC = src/main.c src/fract.c src/utils.c src/key.c src/utils2.c

OBJS = $(SRC:.c=.o)

MLX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all