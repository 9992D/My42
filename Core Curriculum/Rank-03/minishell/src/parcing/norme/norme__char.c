/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme__char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:16:34 by adenny            #+#    #+#             */
/*   Updated: 2025/06/25 01:07:29 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

t_character	*add_char_node(t_charbuilder *b, char c, int type, int word)
{
	t_character	*node;

	node = malloc(sizeof(t_character));
	if (!node)
		return (NULL);
	node->c = c;
	node->type = type;
	node->word = word;
	node->next = NULL;
	if (!b->head)
		b->head = node;
	else
		b->curr->next = node;
	b->curr = node;
	return (node);
}

int		handle_quote(const char **str, t_charbuilder *b)
{
	char	quote;
	int		keep;

	quote = **str;
	keep = !b->state.in_word;
	if (!b->state.in_word)
	{
		b->state.word++;
		b->state.in_word = 1;
	}
	if (keep)
	{
		if (!add_char_node(b, quote, LITERAL, b->state.word))
			return (0);
	}
	(*str)++;
	while (**str && **str != quote)
	{
		if (!add_char_node(b, **str, LITERAL, b->state.word))
			return (0);
		(*str)++;
	}
	if (**str == quote)
	{
		if (keep)
		{
			if (!add_char_node(b, quote, LITERAL, b->state.word))
				return (0);
		}
	}
	return (1);
}

int		handle_non_space(const char **str, t_charbuilder *b)
{
	char	c;
	int	type;

	c = **str;
	type = get_character_type(c);
	if (type == LITERAL)
	{
		if (!b->state.in_word)
		{
			b->state.word++;
			b->state.in_word = 1;
		}
		b->state.last_op = 0;
	}
	else
	{
		if (!b->state.in_word || b->state.last_op != c)
			b->state.word++;
		b->state.in_word = 1;
		b->state.last_op = c;
	}
	if (!add_char_node(b, c, type, b->state.word))
		return (0);
	return (1);
}

int		handle_char(const char **str, t_charbuilder *b)
{
	if (**str == '\'' || **str == '"')
	{
		if (!handle_quote(str, b))
			return (0);
	}
	else if (!ft_isspace(**str))
	{
		if (!handle_non_space(str, b))
			return (0);
	}
	else
	{
		b->state.in_word = 0;
		b->state.last_op = 0;
	}
	return (1);
}
