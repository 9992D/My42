#include "ft_printf.h"

static int valid_format(char c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
            c == 'u' || c == 'x' || c == 'X' || c == '%');
}

static int print_format(char specifier, va_list ap)
{
    int count = 0;

    if (specifier == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *));
    else if (specifier == 'p')
        count += print_pointer(va_arg(ap, void *));
    else if (specifier == 'd' || specifier == 'i')
        count += print_digit((long)va_arg(ap, int), 10, 0);
    else if (specifier == 'u')
        count += print_unsigned_digit(va_arg(ap, unsigned int), 10, 0);
    else if (specifier == 'x')
        count += print_unsigned_digit(va_arg(ap, unsigned int), 16, 0);
    else if (specifier == 'X')
        count += print_unsigned_digit(va_arg(ap, unsigned int), 16, 1);
    else if (specifier == '%')
        count += write(1, "%", 1);
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int count = 0;

    va_start(ap, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (!valid_format(*format))
                return -1; 
            count += print_format(*format, ap);
        }
        else
            count += write(1, format, 1);
        format++;
    }
    va_end(ap);
    return count;
}
