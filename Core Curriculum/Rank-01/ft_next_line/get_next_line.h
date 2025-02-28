/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:43:14 by adenny            #+#    #+#             */
/*   Updated: 2025/02/27 21:26:51 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

typedef struct s_type
{
	char			*content;
	struct s_type	*next;
}					t_type;

int					ft_strlen(char *str);
int					is_it_line(t_type *list);
t_type				*ft_lstlast(t_type *list);
void				generate(char **line, t_type *list);
void				free_all(t_type *list);
void				r_s(int fd, t_type **list);
void				add(t_type **list, char *buffer, int readed);
void				extract(t_type *list, char **line);
void				clean(t_type **list);
char				*get_next_line(int fd);

#endif
