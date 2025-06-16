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
    DOLLAR,
    QUOTE,
    DOUBLE_QUOTE,
    UNKNOWN,
}	t_type;


typedef struct s_character
{
    char			c;
    t_type			type;
    int word;
    struct s_character *next;
} t_character;

typedef struct s_token
{
    char            *str;
    t_type          type;
    struct s_token  *next;
} t_token;

typedef struct s_redir {
    t_type  type;
    char    *target;
    struct  s_redir *next;
} t_redir;

typedef enum e_cmd
{
    NOT_BUILTIN,
	T_ECHO,
    T_CD,
    T_PWD,
    T_EXPORT,
    T_UNSET,
    T_ENV,
    T_EXIT,
}	t_type_cmd;

typedef struct s_command {
    t_type_cmd          cmd;
    char                **args;                          
    t_redir             *redirs;                   
    int                 has_pipe_out;                 
    struct s_command    *next;
    struct s_command    *previous; 
} t_command;

// Utils
int ft_len_without_spaces(const char *str);
int	ft_isspace(char c);

// Character functions
t_type          get_character_type(char c);
void	        free_character_list(t_character *head);
int             malloc_structure_character(t_character **t, int n);
t_character     *build_token_list(const char *str);

// Token functions
void    free_token_list(t_token *head);
int     get_word_len(t_character *chars, int word);
char    *build_token_string(t_character *chars, int len);
t_type  get_operator_token_type(t_character *chars);
t_token *convert_to_tokens(t_character *chars);

// init.c 
t_command *init_struct_globale(t_token *token_list);

// parse_token.c
void        check_redirs(t_token *token_list);
void        parse_token(t_token *token_list);

// utils.c
void        *lst_last_node(void *head);
int         is_redir (t_type type);
int         is_operator(t_type type);
int         is_command(t_type_cmd type);
t_type_cmd  identify_builtin(const char *str);

// free.c
void        cleanup (t_command *cmd);


#endif