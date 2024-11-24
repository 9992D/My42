/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:46:56 by adenny            #+#    #+#             */
/*   Updated: 2024/11/24 16:27:20 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (safe_write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;
	int	written;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		written = safe_write(1, str, 1);
		if (written == -1)
			return (-1);
		count += written;
		str++;
	}
	return (count);
}

int	print_pointer(void *ptr)
{
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
	{
		if (safe_write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (safe_write(1, "0x", 2) == -1)
		return (-1);
	return (2 + print_unsigned_digit(address, 16, 0));
}
