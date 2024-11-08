#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			c;

	p = (unsigned char *)ptr;
	while (c < num)
	{
		p[c] = (unsigned char)value;
		c ++;
	}
	return (ptr);
}
