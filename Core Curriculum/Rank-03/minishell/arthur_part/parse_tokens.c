/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alandel <alandel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:35:52 by alandel           #+#    #+#             */
/*   Updated: 2025/07/03 14:18:31 by alandel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_first_and_last_place(t_token *token_list)
{
	t_token	*last_node;

	last_node = NULL;
	if (token_list->str[0] == 39 || token_list->str[0] == 34
		|| token_list->type == PIPE)
	{
		printf("bash: syntax error near unexpected token\n");
		return (1);
	}
	last_node = lst_last_node(token_list);
	if (last_node && last_node->type == PIPE)
	{
		printf("bash: syntax error near unexpected token\n");
		return (1);
	}
	return (0);
}

// attente nouvelle version amaury pour que str soit bien rempli
static int	check_orphan_quote(t_token *token_list)
{
	t_token	*current;
	int		len;

	current = token_list;
	len = 0;
	while (current)
	{
		if (current->str[0] == 34 || current->str[0] == 39)
		{
			len = strlen(current->str);
			if (len < 2 || current->str[len - 1] != current->str[0])
			{
				printf("bash: syntax error -> find an orphan quote\n");
				return (1);
			}
		}
		current = current->next;
	}
	return (0);
}

// si token commencant et terminant par une quote -> modifier la chaine de caractere pour supprimer [0] et [len-1]
static void	remove_extern_quotes(t_token *token_list)
{
	t_token	*current;
	int		len;
	char	first;
	char	last;

	current = token_list;
	len = 0;
	while (current)
	{
		len = strlen(current->str);
		if (len >= 2)
		{
			first = current->str[0];
			last = current->str[len - 1];
			if ((first == 39 && last == 39) || (first == 34 && last == 34))
			{
				memmove(current->str, current->str + 1, len - 2);
				current->str[len - 2] = '\0';
			}
		}
		current = current->next;
	}
}

// parcourir jusqua tomber sur un token commencant par une double quote, si je rentre dedans jenregistre tout dans une nouvelle string jusqua tomber sur un $USER 
// auquel cas jappelle une fonction venant creer un nouveau noeud (sintercalant au bon endroit)

int	parse_token(t_command *cmd, t_token *token_list, char **line)
{
	if (check_first_and_last_place(token_list))
	{
		cleanall_exit(cmd, token_list, line);
		return (1);
	}
	if (check_orphan_quote(token_list))
	{
		cleanall_exit(cmd, token_list, line);
		return (1);
	}
	// check_variable(token_list);
	remove_extern_quotes(token_list);
	return (0);
}
