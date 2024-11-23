#include "ft_printf.h"

int print_char(int c)
{
    return write(1, &c, 1);
}

int print_str(char *str)
{
    int count = 0;

    if (!str)
        str = "(null)";
    while (*str)
    {
        count += write(1, str, 1);
        str++;
    }
    return count;
}

int print_digit(long n, int base, int uppercase)
{
    int count = 0;
    char *symbols = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n < 0)
    {
        count += write(1, "-", 1);
        n = -n;
    }
    if (n >= base)
        count += print_digit(n / base, base, uppercase);
    count += write(1, &symbols[n % base], 1);
    return count;
}

int print_unsigned_digit(unsigned long n, int base, int uppercase)
{
    int count = 0;
    char *symbols = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

    if (n >= (unsigned long)base)
        count += print_unsigned_digit(n / base, base, uppercase);
    count += write(1, &symbols[n % base], 1);
    return count;
}

int print_pointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;

    if (!ptr)
        return write(1, "(nil)", 5);
    write(1, "0x", 2);
    return 2 + print_unsigned_digit(address, 16, 0);
}
