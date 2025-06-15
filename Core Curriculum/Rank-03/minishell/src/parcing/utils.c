/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:06:58 by adenny            #+#    #+#             */
/*   Updated: 2025/06/15 23:07:00 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_len_without_spaces(const char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			c++;
		i++;
	}
	return (c);
}

int	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
