/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:20 by adenny            #+#    #+#             */
/*   Updated: 2025/02/27 20:49:42 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static t_type	*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	r_s(fd, &l);
	if (l == NULL)
		return (NULL);
	extract(l, &line);
	clean(&l);
	if (line[0] == '\0')
	{
		free_all(l);
		l = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	r_s(int fd, t_type **l)
{
	char	*b;
	int		c;

	c = 1;
	while (!is_it_line(*l) && c != 0)
	{
		b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (b == NULL)
			return ;
		c = (int)read(fd, b, BUFFER_SIZE);
		if ((c == 0 && *l == NULL) || c == -1)
		{
			free(b);
			free_all(*l);
			*l = NULL;
			return ;
		}
		b[c] = '\0';
		add(l, b, c);
		free(b);
	}
}

void	add(t_type **l, char *b, int c)
{
	int		i;
	t_type	*last;
	t_type	*new;

	new = malloc(sizeof(t_type));
	if (new == NULL)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (c + 1));
	if (new->content == NULL)
		return ;
	i = 0;
	while (b[i] && i < c)
	{
		new->content[i] = b[i];
		i++;
	}
	new->content[i] = '\0';
	if (*l == NULL)
	{
		*l = new;
		return ;
	}
	last = ft_lstlast(*l);
	last->next = new;
}

void	extract(t_type *l, char **line)
{
	int	i;
	int	j;

	if (l == NULL)
		return ;
	generate(line, l);
	j = 0;
	while (l)
	{
		i = 0;
		while (l->content[i])
		{
			if ((l->content[i]) == '\n')
			{
				(*line)[j++] = l->content[i++];
				break ;
			}
			(*line)[j++] = l->content[i++];
		}
		l = l->next;
	}
	(*line)[j] = '\0';
}

void	clean(t_type **l)
{
	t_type	*last;
	t_type	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_type));
	if (clean_node == NULL || l == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*l);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content != NULL && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i)
				+ 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_all(*l);
	*l = clean_node;
}
/*
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("f.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("%s", str);
		free(str);
	}
	close(fd);
	return (0);
}*/
