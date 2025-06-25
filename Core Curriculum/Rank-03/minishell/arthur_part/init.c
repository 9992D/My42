#include "../minishell.h"

t_command *create_new_command(void)
{
    t_command *cmd = malloc(sizeof(t_command));
    if (!cmd)
        return NULL;
    cmd->cmd = CMD_NONE; 
    cmd->args = NULL;     
    cmd->nb_args = 0;  
    cmd->redirs = NULL;     
    cmd->has_pipe_out = 0;
    cmd->next = NULL;
    cmd->previous = NULL;
    return cmd;
}

t_command *init_struct_globale(t_token *token_list, char **line)
{
    t_command *cmd = create_new_command();
    if (!cmd)
        return NULL;
    parse_token(cmd, token_list, line);
    save_all(cmd, token_list, line);
    return cmd;
}
