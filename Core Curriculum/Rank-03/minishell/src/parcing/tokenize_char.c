#include "minishell.h"

t_character *build_token_list(const char *str)
{
	t_character *head = NULL;
	t_character *curr = NULL;

	while (*str)
	{
		if (!ft_isspace(*str))
		{
			t_character *new = malloc(sizeof(t_character));
			if (!new)
			{
				free_character_list(head);
				return NULL;
			}
			new->c = *str;
			new->type = get_charactere_type(*str);
			new->next = NULL;
			if (!head)
				head = new;
			else
				curr->next = new;
			curr = new;
		}
		str++;
	}
	return head;
}
