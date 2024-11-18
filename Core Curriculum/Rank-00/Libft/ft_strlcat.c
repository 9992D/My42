#include "libft.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		c++;
	}
	return (c);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	d;
	size_t	e;

	c = 0;
	d = ft_strlen(dst);
	e = ft_strlen((char *)src);
	if (dstsize <= d)
		return (e + d);
	while (src[c] && c < dstsize - d - 1)
	{
		dst[d + c] = src[c];
		c++;
	}
	dst[d + c] = '\0';
	return (d + e);
}
