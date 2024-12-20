/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:40:03 by adenny            #+#    #+#             */
/*   Updated: 2024/12/20 03:20:18 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// Fonction interne pour remplir la variable `readed` avec les données lues
static char	*_fill_readed(int fd, char *readed, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(readed);
			return (NULL);
		}
		buffer[b_read] = '\0';
		if (!readed)
			readed = ft_strdup("");
		if (!readed)
			return (NULL); // Échec de ft_strdup
		tmp = readed;
		readed = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!readed)
			return (NULL); // Échec de ft_strjoin
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (readed);
}

// Fonction interne pour extraire la ligne complète et mettre à jour `readed`
static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	size_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == '\0')
		return (NULL);
	if (line_buffer[i + 1] == '\0')
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i - 1);
	if (!left_c)
		return (NULL);
	if (*left_c == '\0')
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (left_c);
}

// Fonction principale pour obtenir la prochaine ligne du fichier
char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*readed;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	// Vérification du descripteur de fichier et des paramètres
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(readed);
		readed = NULL;
		free(buffer);
		return (NULL);
	}
	line = _fill_readed(fd, readed, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(readed);
		readed = NULL;
		return (NULL);
	}
	readed = _set_line(line);
	return (line);
}