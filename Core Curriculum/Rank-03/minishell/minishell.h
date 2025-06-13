#ifndef MINISHELL_H
# define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <dirent.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <term.h>

typedef enum e_token_type
{
	LITERAL,
    PIPE,
    AND,
    OR,
    REDIR_IN,
    REDIR_OUT,
    UNKNOWN,
}	t_token_type;

typedef struct s_token
{
	char			c;
	t_token_type	type;
	struct s_token *next;
} t_token;

int ft_len_without_spaces(const char *str);
int	ft_isspace(char c);

#endif