NAME = pipex
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c utils.c libft.c split.c childs.c
OBJS = $(SRCS:.c=.o)
INC = -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re