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

void free_args(t_arg *args, size_t nb_args)
{
    size_t i;

    i = 0;
    if (!args)
        return;

    while (i < nb_args)
        free(args[i++].str);

    free(args);
}

void cleanup(t_command *cmd)
{
    t_command *current = cmd;
    t_command *next;

    while (current)
    {
        next = current->next;
        free_args(current->args, current->nb_args);
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
