/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:07:25 by adenny            #+#    #+#             */
/*   Updated: 2025/06/15 23:07:26 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_token_list(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}

int	get_word_len(t_character *chars, int word)
{
	int	len;

	len = 0;
	while (chars && chars->word == word)
	{
		len++;
		chars = chars->next;
	}
	return (len);
}

char	*build_token_string(t_character *chars, int len)
{
	char	*str;
	int		i;

	str = malloc(len + 1);
	i = 0;
	if (!str)
		return (NULL);
	while (i < len && chars)
	{
		str[i++] = chars->c;
		chars = chars->next;
	}
	str[i] = '\0';
	return (str);
}

t_type	get_operator_token_type(t_character *chars)
{
	if (chars->c == '<')
		return (HEREDOC);
	if (chars->c == '>')
		return (APPEND);
	if (chars->c == '|')
		return (OR);
	if (chars->c == '&')
		return (AND);
	return (chars->type);
}
