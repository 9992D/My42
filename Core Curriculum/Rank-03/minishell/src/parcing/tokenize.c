/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:23:35 by adenny            #+#    #+#             */
/*   Updated: 2025/07/02 21:10:10 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_character	*build_token_list(const char *str)
{
	t_charbuilder	b;

	b = (t_charbuilder){0};
	while (*str)
	{
		if (!handle_char(&str, &b))
			return (free_character_list(b.head), NULL);
	}
	return (b.head);
}

t_token	*convert_to_tokens(t_character *chars)
{
	t_token		*token_head;
	t_token		*current_token;
	t_token		*new_token;
	t_character	*original;
	int			word_id;

	token_head = NULL;
	current_token = NULL;
	original = chars;
	while (chars)
	{
		word_id = chars->word;
		new_token = create_token_from_chars(chars, word_id);
		if (!new_token)
		{
			free_token_list(token_head);
			free_character_list(original);
			return (NULL);
		}
		append_token(&token_head, &current_token, new_token);
		while (chars && chars->word == word_id)
			chars = chars->next;
	}
	free_character_list(original);
	return (token_head);
}
