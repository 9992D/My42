/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:48:33 by adenny            #+#    #+#             */
/*   Updated: 2024/11/27 18:53:38 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NEXT_LINE_H
# define FT_NEXT_LINE_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
char	*_set_line(char *line_buffer);

#endif