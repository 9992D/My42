#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t k;

	if (!f || !s)
		return (NULL);
	char *result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (s[k])
	{
		result[k] = f(k, s[k]);
		k++;
	}
	result[k] = '\0';
	return (result);
}