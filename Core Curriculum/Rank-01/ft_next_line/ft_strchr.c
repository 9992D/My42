/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:48:12 by adenny            #+#    #+#             */
/*   Updated: 2024/11/27 18:48:15 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == (char)c)
			return ((char *)&str[k]);
		k++;
	}
	if ((char)c == '\0')
		return ((char *)&str[k]);
	return (NULL);
}
