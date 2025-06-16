#include "../minishell.h"

static void free_redir(t_redir *redir)
{
    t_redir *current = redir;
    while (current)
    {
        t_redir *next = current->next;
        if (current->target)
            free(current->target);
        free(current);
        current = next;
    }
}

static void free_args(char **args)
{
    int i = 0;

    if (!args)
        return;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void cleanup(t_command *cmd)
{
    t_command *current = cmd;

    while (current)
    {
        t_command *next = current->next;
        free_args(current->args);
        free_redir(current->redirs);
        free(current);
        current = next;
    }
}

void cleanall_exit(t_command *cmd, t_token *token_list)
{
    cleanup(cmd);
    free_token_list(token_list);
    // free(line); LEAKS OBLIGATOIRE pour l'instant car line de readline n'est pas free
    exit(EXIT_FAILURE);
}
