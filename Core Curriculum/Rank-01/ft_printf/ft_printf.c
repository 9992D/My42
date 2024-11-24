/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:47:03 by adenny            #+#    #+#             */
/*   Updated: 2024/11/24 14:52:18 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	safe_write(int fd, const void *buf, size_t count)
{
	ssize_t	ret;

	ret = write(fd, buf, count);
	if (ret == -1)
		return (-1);
	return ((int)ret);
}

static int	valid_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

static int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (print_str(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_digit(va_arg(ap, int), 10));
	else if (specifier == 'u')
		return (print_unsigned_digit(va_arg(ap, unsigned int), 10, 0));
	else if (specifier == 'x')
		return (print_unsigned_digit(va_arg(ap, unsigned int), 16, 0));
	else if (specifier == 'X')
		return (print_unsigned_digit(va_arg(ap, unsigned int), 16, 1));
	else if (specifier == '%')
		return (safe_write(1, "%", 1));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		temp;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format && valid_format(*format))
				temp = print_format(*format, ap);
			else
				temp = -1;
		}
		else
		{
			temp = safe_write(1, format, 1);
		}
		if (temp == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += temp;
		format++;
	}
	va_end(ap);
	return (count);
}
