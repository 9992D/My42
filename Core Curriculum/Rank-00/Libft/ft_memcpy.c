#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char		*d;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	while (count > 0)
	{
		*d = *s;
		d++;
		s++;
		count--;
	}
	return (dest);
}