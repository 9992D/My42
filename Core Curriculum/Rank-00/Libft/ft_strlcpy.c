#include "libft.h"

size_t	ft_strlcpy(char *string1, const char *string2, size_t count)
{
	size_t c = 0;
	while (string2[c] && c <= count - 1)
	{
		string1[c] = string2[c];
		c++;
	}
	while (string2[c])
		c++;
	if (count == 0)
		return (c);
	string1[c] = '\0';
	return (c);
}