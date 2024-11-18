#include "libft.h"

size_t	ft_strlcpy(char *string1, const char *string2, size_t count)
{
	size_t	c;
	size_t	i;

	c = 0;
	while (string2[c])
		c++;
	if (count == 0)
		return (c);
	i = 0;
	while (i < count - 1 && string2[i])
	{
		string1[i] = string2[i];
		i++;
	}
	string1[i] = '\0';
	return (c);
}