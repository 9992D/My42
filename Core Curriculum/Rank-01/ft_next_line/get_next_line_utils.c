/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:24 by adenny            #+#    #+#             */
/*   Updated: 2025/02/27 20:49:18 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

int	is_it_line(t_type *l)
{
	int		i;
	t_type	*current;

	if (l == NULL)
		return (0);
	current = ft_lstlast(l);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_type	*ft_lstlast(t_type *l)
{
	t_type	*current;

	if (l == NULL)
		return (NULL);
	current = l;
	while (current->next)
		current = current->next;
	return (current);
}

void	generate(char **line, t_type *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
}

void	free_all(t_type *list)
{
	t_type	*current;
	t_type	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
