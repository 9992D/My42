#include <stddef.h>

char	*ft_strrchr(const char *str, int c)
{
	int k;

	k = 0;
	while (str[k])
		k++;
	while (k >= 0)
	{
		if (str[k] == c)
			return ((char *)&str[k]);
		k--;
	}
	return (NULL);
}