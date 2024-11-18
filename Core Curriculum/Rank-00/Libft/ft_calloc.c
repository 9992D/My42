#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, count * size);

	return (ptr);
}