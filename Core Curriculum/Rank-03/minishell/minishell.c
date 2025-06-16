#include "minishell.h"

const char *get_cmd_name(t_type_cmd cmd)
{
    switch (cmd)
    {
        case T_ECHO: return "echo";
        case T_CD: return "cd";
        case T_PWD: return "pwd";
        case T_EXPORT: return "export";
        case T_UNSET: return "unset";
        case T_ENV: return "env";
        case T_EXIT: return "exit";
        default: return "not_builtin";
    }
}

const char *get_type_name(t_type type)
{
    switch (type)
    {
        case LITERAL: return "LITERAL";
        case PIPE: return "PIPE";
        case REDIR_IN: return "<";
        case HEREDOC: return "<<";
        case REDIR_OUT: return ">";
        case APPEND: return ">>";
        case OR: return "or";
        case AMPERSAND: return "ampersand";
        case AND: return "and";
        case DOLLAR: return "dollar";
        case QUOTE: return "quote";
        case DOUBLE_QUOTE: return "double_quote";
        default: return "UNKNOWN";
    }
}

void print_tokens(t_token *token_list)
{
    while (token_list)
    {
        printf("Token: '%s' [Type: %d]\n", token_list->str, token_list->type);
        token_list = token_list->next;
    }
}

void print_command_structure(t_command *cmd_list)
{
    while (cmd_list)
    {
        printf(" (cmd)[LITERAL]-> %s", get_cmd_name(cmd_list->cmd));

        int j = 0;
        while (cmd_list->args && cmd_list->args[j])
        {
            printf(" (args)[%s]-> %s", get_type_name(LITERAL), cmd_list->args[j]);
            j++;
        }

        t_redir *r = cmd_list->redirs;
        while (r)
        {
            printf(" (redir)[%s]-> %s", get_type_name(r->type), get_type_name(r->type));
            printf(" (target)[%s]-> %s", get_type_name(r->type), r->target);
            r = r->next;
        }

		while (cmd_list->args && cmd_list->args[j])
        {
            printf(" (args)[%s]-> %s", get_type_name(LITERAL), cmd_list->args[j]);
            j++;
        }

        if (cmd_list->has_pipe_out)
            printf(" \n[PIPE]-> |");

        printf("\n");
        cmd_list = cmd_list->next;
    }
}

int main(void)
{
    char *line;

    while (1)
    {
        line = readline("minishell$ ");
        if (!line)
        {
            printf("exit\n");
            break;
        }

        // Vérifier si la ligne n'est pas vide
        if (*line == '\0')
        {
            free(line);
            continue;
        }

        if (*line)
            add_history(line);

        t_character *char_list = build_token_list(line);
        if (!char_list)
        {
            fprintf(stderr, "Error building character list.\n");
            free(line);
            continue;
        }

        t_token *token_list = convert_to_tokens(char_list);
        if (!token_list)
        {
            fprintf(stderr, "Error converting to tokens.\n");
            free_character_list(char_list);
            free(line);
            continue;
        }

        t_command *cmd_list = init_struct_globale(token_list);
        if (!cmd_list)
        {
            fprintf(stderr, "Error parsing command list.\n");
            free_token_list(token_list);
            free_character_list(char_list);
            free(line);
            continue;
        }

        print_command_structure(cmd_list);
        cleanup(cmd_list);
        free_token_list(token_list);
        free(line);
    }

    return 0;
}