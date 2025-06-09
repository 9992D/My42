NAME = push_swap

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c push_swap__utils.c push_swap__init.c push_swap__sort.c push_swap__movement.c push_swap__checker_main.c
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
