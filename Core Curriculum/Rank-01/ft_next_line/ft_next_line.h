/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:48:33 by adenny            #+#    #+#             */
/*   Updated: 2024/11/27 18:48:40 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NEXT_LINE
# define FT_NEXT_LINE

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

#endif
