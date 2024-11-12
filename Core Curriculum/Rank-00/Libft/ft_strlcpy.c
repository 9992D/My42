#include <stddef.h>

size_t	strlcpy(char *string1, const char *string2, size_t count)
{
	size_t c = 0;
	while (string2[c] && c < count - 1)
	{
		string1[c] = string2[c];
		c++;
	}
	string1[c] = '\0';
	while (string2[c])
		c++;
	if (count == 0)
		return (strlen(string2));
	return (c);
}