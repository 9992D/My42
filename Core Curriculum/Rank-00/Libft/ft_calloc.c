#include <stddef.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			c;

	p = (unsigned char *)ptr;
	while (c < num)
	{
		p[c] = (unsigned char)value;
		c++;
	}
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t total_size = count * size;
	void *ptr;

	if (count == 0 || size == 0)
		return (NULL);
	if (count != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}