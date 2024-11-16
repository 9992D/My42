# include <stddef.h>

int	ft_tolower(int c)
{
	if (c >= 97 && c <= 122)
		return (c + 32);
	return (c);
}
