NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Compilation terminée : $(NAME)"

%.o: %.c get_next_line.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@echo "Fichiers objets supprimés."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) supprimé."

re: fclean all

.PHONY: all clean fclean re
