/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:59:00 by adenny            #+#    #+#             */
/*   Updated: 2024/11/24 16:22:07 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base)
{
	const char	*symbols = "0123456789abcdef";
	int			count;

	count = 0;
	if (n < 0)
	{
		if (safe_write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	if (n / base > 0)
	{
		count += print_digit(n / base, base);
		if (count == -1)
			return (-1);
	}
	if (safe_write(1, &symbols[n % base], 1) == -1)
		return (-1);
	return (count + 1);
}

int	print_unsigned_digit(unsigned long n, int base, int uppercase)
{
	const char	*symbols;
	int			count;

	count = 0;
	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n / base > 0)
	{
		count += print_unsigned_digit(n / base, base, uppercase);
		if (count == -1)
			return (-1);
	}
	if (safe_write(1, &symbols[n % base], 1) == -1)
		return (-1);
	return (count + 1);
}
