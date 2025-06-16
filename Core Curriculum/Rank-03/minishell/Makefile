NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = minishell.c src/parcing/char.c src/parcing/utils.c src/parcing/tokenize.c src/parcing/token.c src/parcing/norme/norme__char.c src/parcing/norme/norme__token.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
