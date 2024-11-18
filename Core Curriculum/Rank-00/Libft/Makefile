NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard ft_*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created successfully."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
