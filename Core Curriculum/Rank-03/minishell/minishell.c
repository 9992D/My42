#include "minishell.h"

void print_tokens(t_token *token_list)
{
	while (token_list)
	{
		printf("Token: '%s' [Type: %d]\n", token_list->str, token_list->type);
		token_list = token_list->next;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s \"command line\"\n", av[0]);
		return 1;
	}
	t_character *char_list = build_token_list(av[1]);
	if (!char_list)
	{
		fprintf(stderr, "Error building character list.\n");
		return 1;
	}
	t_token *token_list = convert_to_tokens(char_list);
	if (!token_list)
	{
		fprintf(stderr, "Error converting to tokens.\n");
		return 1;
	}
	print_tokens(token_list);
	free_token_list(token_list);
	return 0;
}
