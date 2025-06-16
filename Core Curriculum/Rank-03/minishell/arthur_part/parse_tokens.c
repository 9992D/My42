#include "../minishell.h"

static int check_first_and_last_place(t_token *token_list)
{
    t_token *last_node = NULL;
    if (token_list->type == QUOTE || token_list->type == DOUBLE_QUOTE || token_list->type == PIPE)
    {
        printf("bash: syntax error near unexpected token\n");
        return 0;
    }
    
    last_node = lst_last_node(token_list);
    if (last_node && last_node->type == PIPE)
    {
        printf("bash: syntax error near unexpected token\n");
        return 0;
    }
    return 1;
}

static void check_dollars(t_token *token_list)
{
    while (token_list)
    {
        char *str = token_list->str;
        int len = strlen(str);
        
        if (!strchr(str, '$'))
        {
            token_list = token_list->next;
            continue;
        }
        if (str[0] == 39 && str[len - 1] == 39)
        {
            token_list = token_list->next;
            continue;
        }
        if (str[0] == 34 && str[len - 1] == 34)
        {
            token_list->type = DOLLAR;
            token_list = token_list->next;
            continue;
        }
        token_list = token_list->next;
    }
}

void parse_token(t_command *cmd, t_token *token_list)
{ 
    if (!check_first_and_last_place(token_list))
        cleanall_exit(cmd, token_list);

    check_dollars(token_list);
}

