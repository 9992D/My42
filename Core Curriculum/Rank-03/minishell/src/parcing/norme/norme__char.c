/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme__char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:16:34 by adenny            #+#    #+#             */
/*   Updated: 2025/07/02 21:53:35 by adenny           ###   ########.fr       */
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

int handle_char(const char **str, t_charbuilder *b)
{
    // 1. Espace (hors quote) -> termine le mot courant
    if (ft_isspace(**str)) {
        b->state.in_word = 0;
        b->state.in_quote = 0;
        b->state.last_op = 0;
        (*str)++;
        return 1;
    }
    // 2. Quotes : on commence TOUJOURS un nouveau token pour chaque quote ouvrante
    else if (**str == '\'' || **str == '"') {
        b->state.word++;
        b->state.in_word = 1;
        b->state.in_quote = **str;
        return handle_quote(str, b);
    }
    // 3. Dollar
    else if (**str == '$') {
        if (!b->state.in_word) {
            b->state.word++;
            b->state.in_word = 1;
        }
        return handle_dollar(str, b);
    }
    // 4. Opérateurs spéciaux
    else if (get_character_type(**str) != LITERAL) {
        b->state.word++;
        b->state.in_word = 1;
        b->state.last_op = **str;
        if (!add_char_node(b, **str, get_character_type(**str), b->state.word))
            return 0;
        (*str)++;
        return 1;
    }
    // 5. Caractère normal : commence un nouveau mot si on n'est pas déjà dans un mot
    else {
        if (!b->state.in_word) {
            b->state.word++;
            b->state.in_word = 1;
        }
        if (!add_char_node(b, **str, LITERAL, b->state.word))
            return 0;
        (*str)++;
    }
    return 1;
}

int handle_quote(const char **str, t_charbuilder *b)
{
    char quote = **str;
    (*str)++;

    while (**str && **str != quote) {
        if (!add_char_node(b, **str, LITERAL, b->state.word))
            return 0;
        (*str)++;
    }
    if (**str == quote)
        (*str)++;

    b->state.in_word = 0;
    b->state.in_quote = 0;
    return 1;
}

int handle_non_space(const char **str, t_charbuilder *b)
{
    char    c = **str;
    int     type = get_character_type(c);

    if (!b->state.in_quote)
    {
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
    }
    if (!add_char_node(b, c, type, b->state.word))
        return (0);
    return (1);
}

static int is_name_char(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c == '_') ||
            (c >= '0' && c <= '9'));
}

static int is_special_param(char c)
{
    return (c == '*' || c == '@' || c == '#' || c == '?' ||
            c == '-' || c == '$' || c == '!' || c == '0');
}

int handle_dollar(const char **str, t_charbuilder *b)
{
	int word = b->state.in_word ? b->state.word : ++b->state.word;
	b->state.in_word = 1;

	if (*(*str + 1) == '{')
	{
		*str += 2;
		if (is_name_char(**str))
		{
			add_char_node(b, '$', VARIABLE, word);
			while (**str && is_name_char(**str))
				add_char_node(b, *(*str)++, VARIABLE, word);
		}
		else if (is_special_param(**str))
		{
			add_char_node(b, '$', VARIABLE, word);
			add_char_node(b, *(*str)++, VARIABLE, word);
			b->state.in_word = 0;
			while (**str && **str != '}')
			{
				if (!b->state.in_word)
				{
					b->state.word++;
					b->state.in_word = 1;
				}
				add_char_node(b, *(*str)++, LITERAL, b->state.word);
			}

			if (**str == '}')
				(*str)++;
			return 1;
		}
		else
		{
			add_char_node(b, '$', LITERAL, word);
		}
		while (**str && **str != '}')
			add_char_node(b, *(*str)++, LITERAL, word);

		if (**str == '}')
			(*str)++;
		return 1;
	}
	(*str)++; 
	if (is_name_char(**str))
	{
		add_char_node(b, '$', VARIABLE, word);
		while (**str && is_name_char(**str))
			add_char_node(b, *(*str)++, VARIABLE, word);
		return 1;
	}
	else if (is_special_param(**str))
	{
		add_char_node(b, '$', VARIABLE, word);
		add_char_node(b, *(*str)++, VARIABLE, word);
		return 1;
	}
	add_char_node(b, '$', LITERAL, word);
	if (**str)
		add_char_node(b, *(*str)++, LITERAL, word);
	return 1;
}
