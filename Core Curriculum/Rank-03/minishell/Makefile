NAME     := minishell
CC       := cc
CFLAGS   := -Wall -Wextra -Werror
LDFLAGS  := -lreadline

SRCS := \
	minishell.c \
	src/parcing/char.c \
	src/parcing/utils.c \
	src/parcing/tokenize.c \
	src/parcing/token.c \
	src/parcing/norme/norme__char.c \
	src/parcing/norme/norme__token.c \
	arthur_part/init.c \
	arthur_part/free.c \
	arthur_part/utils.c \
	arthur_part/parse_tokens.c \
	arthur_part/cmd.c

OBJDIR := obj
OBJS   := $(SRCS:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
