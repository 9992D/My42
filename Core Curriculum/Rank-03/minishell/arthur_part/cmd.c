#include "../minishell.h"

static void add_redir(t_command *cmd, t_type type, char *target)
{
    t_redir *redir = malloc(sizeof(*redir));
    if (!redir)
        return;

    redir->type = type;

    if (target != NULL && target[0] != '\0')
    {
        redir->target = strdup(target);
        if (!redir->target)
        {
            free(redir);
            return;
        }
        redir->error = 0;
    }
    else
    {
        redir->target = NULL;
        redir->error  = 1;
    }

    redir->next = cmd->redirs;
    cmd->redirs = redir;
}


static int add_cmd(t_command *cmd, char *str)
{
    if (cmd->cmd == NOT_BUILTIN)
    {
        cmd->cmd = identify_builtin(str);
        return 1;
    }
    return 0;
}

static void add_argument(t_command *cmd, char *arg)
{
    int i = 0;
    int j = 0;
    char **new_args;

    if (cmd->cmd == NOT_BUILTIN)
        return;

    if (!cmd->args)
    {
        cmd->args = malloc(sizeof(char *) * 2);
        cmd->args[0] = strdup(arg);
        cmd->args[1] = NULL;
        return;
    }
    while (cmd->args[i])
        i++;
    new_args = malloc(sizeof(char *) * (i + 2));
    while (j < i) 
    { 
        new_args[j] = cmd->args[j];
        j++;
    }
    new_args[i] = strdup(arg);
    new_args[i + 1] = NULL;
    free(cmd->args);
    cmd->args = new_args;
}

void save_all(t_command *cmd, t_token *token_list)
{
    t_command *current = cmd;

    while (token_list)
    {
        if (token_list->type == PIPE)
        {
            t_command *new_node = create_new_command();
            current->has_pipe_out = 1;
            current->next = new_node;
            new_node->previous = current;
            current = new_node;
            token_list = token_list->next;
            continue;
        }
       
        if (is_redir(token_list->type))
        {
            if (token_list->next && token_list->next->type == LITERAL)
            {
                add_redir(current, token_list->type, token_list->next->str);
                token_list = token_list->next->next;
            }
            else
            {
                add_redir(current, token_list->type, NULL);
                token_list = token_list->next;
            }
            continue;
        }

        else if (token_list->type == LITERAL)
        {
            if (add_cmd(current, token_list->str))
            {
                token_list = token_list->next;
                continue;
            }
            add_argument(current, token_list->str);
        }
        token_list = token_list->next;
    }
}
