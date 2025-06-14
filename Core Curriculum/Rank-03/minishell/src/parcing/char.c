#include "minishell.h"

t_type get_character_type(char c)
{
	if ((c >= 'a' && c <= 'z') || 
	    (c >= 'A' && c <= 'Z') || 
	    (c >= '0' && c <= '9'))
		return LITERAL;
	else if (c == '|')
		return PIPE;
	else if (c == '&')
		return AMPERSAND;
	else if (c == '<')
		return REDIR_IN;
	else if (c == '>')
		return REDIR_OUT;
	return UNKNOWN;
}

void	free_character_list(t_character *head)
{
	t_character *tmp;

	while (head)
	{
		tmp = head->next;
		if (head->type)
			free(head->type);

		free(head);
		head = tmp;
	}
}

int malloc_structure_character(t_character **t, int n)
{
	t_character *head = NULL;
	t_character *curr = NULL;

	while (n > 0)
	{
		t_character *new = malloc(sizeof(t_character));
		if (!new)
		{
			free_character_list(head);
			return 0;
		}
		new->c = NULL;
		new->type = NULL;
		new->next = NULL;
		if (!head)
			head = new;
		else
			curr->next = new;

		curr = new;
		n--;
	}
	*t = head;
	return 1;
}