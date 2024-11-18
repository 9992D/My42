#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] == (char)c)
			return ((char *)&str[k]);
		k++;
	}
	if ((char)c == '\0')
		return ((char *)&str[k]);
	return (NULL);
}
