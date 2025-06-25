#include "../minishell.h"

static int check_first_and_last_place(t_token *token_list)
{
    t_token *last_node = NULL;
    if (token_list->type == QUOTE || token_list->type == DOUBLE_QUOTE || token_list->type == PIPE)
    {
        printf("bash: syntax error near unexpected token\n");
        return 1;
    }
    
    last_node = lst_last_node(token_list);
    if (last_node && last_node->type == PIPE)
    {
        printf("bash: syntax error near unexpected token\n");
        return 1;
    }
    return 0;
}

// check quote orpheline dans la ligne -> quitter
static int check_orphan_quote(t_token *token_list)
{
    t_token *current = token_list;
    while(current)
    {
        if (current->type == QUOTE)
            return 1;

        current = current->next;
    }
    return 0;
}


// check si jai une quote simple dans un token - puis while (token != quote simple) je verifie si il ya un token de type variable auquel cas type = LITERAL
// static void check_variable(t_token *token_list)
// {
//     t_token *current = token_list;
//     t_token *wait_quote;
//     while(current)
//     {
//         if (current->str[0] == 39) // simple quote
//         {
//             while(wait_quote && strchr)
//         }
//         current = current->next;
//     }
// }

// si token commencant et terminant par une quote -> modifier la chaine de caractere pour supprimer [0] et [len-1]
// static void remove_extern_quotes(t_token *token_list)
// {
//     t_token *current = token_list;
//     int len = 0;
//     char first;
//     char last;
//     while(current)
//     {
//         len = strlen(current->str);
//         if (len >= 2)
//         {
//             first = current->str[0];
//             last = current->str[len-1];
//             if ((first == 39 && last == 39) || (first == 34 && last == 34))
//             {
//                 memmove(current->str, current->str + 1, len - 2);
//                 current->str[len-2] = '\0';
//             }
//         }
//         current = current->next;
//     }
// }

// static void remove_intern_quotes(t_token *token_list)
// {
//     t_token *current = token_list;
//     int len = 0;

// }

void parse_token(t_command *cmd, t_token *token_list, char **line)
{ 
    //checker la validite du premier et dernier caractere de la liste
    if (check_first_and_last_place(token_list))
        cleanall_exit(cmd, token_list, line);

    // check quote orpheline dans la ligne -> quitter
    if (check_orphan_quote(token_list))
        cleanall_exit(cmd, token_list, line);

    // quote simple dans un token (peu importe ou) - puis while (token != quote simple) si token de type variable auquel cas type = LITERAL
     // check_variable(token_list);
    // supprimer les quotes s/d au sein d'un token SANS quotes externe.
     // remove_intern_quotes(token_list);
    // si token commencant et terminant par une quote -> modifier la chaine de caractere pour supprimer [0] et [len-1]
     // remove_extern_quotes(token_list);


     
   
  
}
