#include "ft_printf.h"

int	print_digit(long n, int base)
{
	char	buffer[65];
	int		i;
	int		count;
	char	symbols[] = "0123456789abcdef";

	i = 64;
	count = 0;
	if (n < 0)
	{
		if (safe_write(1, "-", 1) == -1)
			return (-1);
		count++;
		n = -n;
	}
	buffer[i--] = '\0';
	while (n > 0)
	{
		buffer[i--] = symbols[n % base];
		n /= base;
	}
	if (i == 64)
	{
		buffer[i--] = '0';
	}
	if (safe_write(1, &buffer[i + 1], 64 - i - 1) == -1)
		return (-1);
	count += (64 - i - 1);
	return (count);
}

int	print_unsigned_digit(unsigned long n, int base, int uppercase)
{
	char		buffer[65];
	int			i;
	const char	*symbols;

	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	i = 64;
	buffer[i--] = '\0';
	while (n > 0)
	{
		buffer[i--] = symbols[n % base];
		n /= base;
	}
	if (i == 64)
	{
		buffer[i--] = '0';
	}
	if (safe_write(1, &buffer[i + 1], 64 - i - 1) == -1)
		return (-1);
	return (64 - i - 1);
}