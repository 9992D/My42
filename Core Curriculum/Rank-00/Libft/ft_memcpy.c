#include "libft.h"

void	*ft_memcpy(void *__restrict__ dest, const void *__restrict__ src,
		size_t count)
{
	char *d = (char *)dest;
	const char *s = (const char *)src;
	while (count > 0)
	{
		*d = *s;
		d++;
		s++;
		count--;
	}
	return (dest);
}