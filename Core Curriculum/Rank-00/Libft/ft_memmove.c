#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char *d;
	const char *s;

	if ((!dest || !src) && count > 0)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
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