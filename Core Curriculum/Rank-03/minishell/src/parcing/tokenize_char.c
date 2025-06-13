#include "minishell.h"

t_token *build_token_list(const char *str)
{
	t_token *head = NULL;
	t_token *curr = NULL;

	while (*str)
	{
		if (!ft_isspace(*str))
		{
			t_token *new = malloc(sizeof(t_token));
			if (!new)
			{
				while (head)
				{
					t_token *tmp = head->next;
					free(head);
					head = tmp;
				}
				return NULL;
			}
			new->c = *str;
			new->type = get_token_type(*str);
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
