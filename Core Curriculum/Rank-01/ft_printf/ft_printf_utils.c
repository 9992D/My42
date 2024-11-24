/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:01:16 by adenny            #+#    #+#             */
/*   Updated: 2024/11/24 22:01:18 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int safe_write(int fd, const void *buf, size_t count)
{
    ssize_t ret;

    ret = write(fd, buf, count);
    if (ret == -1)
        return -1;
    return (int)ret;
}

int print_char(int c)
{
    return safe_write(1, &c, 1);
}

int print_str(char *str)
{
    int count;
    int written;

    count = 0;
    if (!str)
        str = "(null)";
    while (*str)
    {
        written = safe_write(1, str, 1);
        if (written == -1)
            return -1;
        count += written;
        str++;
    }
    return count;
}

int print_digit(long n, int base)
{
    char buffer[65];
    int i;
    int count;
    char symbols[] = "0123456789abcdef";

    i = 64;
    count = 0;
    if (n < 0)
    {
        if (safe_write(1, "-", 1) == -1)
            return -1;
        count++;
        n = -n;
    }
    buffer[i--] = '\0';
    do
    {
        buffer[i--] = symbols[n % base];
        n /= base;
    } while (n > 0);
    if (safe_write(1, &buffer[i + 1], 64 - i - 1) == -1)
        return -1;
    count += (64 - i - 1);
    return count;
}

int print_unsigned_digit(unsigned long n, int base, int uppercase)
{
    char buffer[65];
    int i;
    const char *symbols;

    if (uppercase)
        symbols = "0123456789ABCDEF";
    else
        symbols = "0123456789abcdef";

    i = 64;
    buffer[i--] = '\0';
    do
    {
        buffer[i--] = symbols[n % base];
        n /= base;
    } while (n > 0);
    if (safe_write(1, &buffer[i + 1], 64 - i - 1) == -1)
        return -1;
    return (64 - i - 1);
}

int print_pointer(void *ptr)
{
    unsigned long address;

    address = (unsigned long)ptr;
    if (!ptr)
    {
        if (safe_write(1, "0x0", 3) == -1)
            return -1;
        return 3;
    }
    if (safe_write(1, "0x", 2) == -1)
        return -1;
    return (2 + print_unsigned_digit(address, 16, 0));
}
