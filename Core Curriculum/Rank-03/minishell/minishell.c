#include "minishell.h"

void print_tokens(t_token *token_list)
{
	while (token_list)
	{
		printf("Token: '%s' [Type: %d]\n", token_list->str, token_list->type);
		token_list = token_list->next;
	}
}

int main(void)
{
    char *input = readline("minishell> ");
    if (!input)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    t_character *char_list = build_token_list(input);
    if (!char_list)
    {
        fprintf(stderr, "Error building character list.\n");
        free(input);
        return 1;
    }

    t_token *token_list = convert_to_tokens(char_list);
    if (!token_list)
    {
        fprintf(stderr, "Error converting to tokens.\n");
        free(input);
        return 1;
    }

    print_tokens(token_list);
    free_token_list(token_list);
    free(input);
    return 0;
}