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

typedef enum e_type
{
	LITERAL,
    PIPE,
    OR,
    AMPERSAND,
    AND,
    REDIR_IN,
    HEREDOC,
    REDIR_OUT,
    APPEND,
    UNKNOWN,
}	t_type;

typedef struct s_character
{
    char			c;
    t_type			type;
    struct s_character *next;
} t_character;

typedef struct s_token
{
    char *str;
    t_type type;
    struct s_str *next;
} t_token;

// Utils
int ft_len_without_spaces(const char *str);
int	ft_isspace(char c);

// Character functions
t_type get_character_type(char c);
void	free_character_list(t_character *head);
int malloc_structure_character(t_character **t, int n);
t_character *build_token_list(const char *str);

#endif