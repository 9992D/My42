#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char		*d;
	const char	*s = (const char *)src;

	d = (char *)dest;
	if (d < s)
	{
		while (count--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += count;
		s += count;
		while (count--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
