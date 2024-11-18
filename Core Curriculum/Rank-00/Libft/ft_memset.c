#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			c;

	c = 0;
	p = (unsigned char *)ptr;
	while (c < num)
	{
		p[c] = (unsigned char)value;
		c ++;
	}
	return (ptr);
}
