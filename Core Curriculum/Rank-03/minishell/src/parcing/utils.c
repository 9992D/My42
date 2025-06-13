#include "minishell.h"

int ft_len_without_spaces(const char *str)
{
    int i = 0;
    int c = 0;

    while (str[i])
    {
        if (!ft_isspace(str[i]))
            c++;
        i++;
    }
    return c;
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int malloc_structure_character(t_token **t, int n)
{
	t_token *head = NULL;
	t_token *curr = NULL;

	while (n > 0)
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

t_token_type get_token_type(char c)
{
	if ((c >= 'a' && c <= 'z') || 
	    (c >= 'A' && c <= 'Z') || 
	    (c >= '0' && c <= '9'))
		return LITERAL;
	else if (c == '|')
		return PIPE;
	else if (c == '&')
		return AND;
	else if (c == '<')
		return REDIR_IN;
	else if (c == '>')
		return REDIR_OUT;
	return UNKNOWN;
}
