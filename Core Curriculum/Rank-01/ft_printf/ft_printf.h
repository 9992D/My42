/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:00:53 by adenny            #+#    #+#             */
/*   Updated: 2024/11/23 22:00:56 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int c);
int	print_str(char *str);
int	print_digit(long n, int base, int uppercase);
int	print_unsigned_digit(unsigned long n, int base, int uppercase);
int	print_pointer(void *ptr);

#endif
