#include "libft.h"

size_t	ft_strlen_const(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t k;

	if (!f || !s)
		return (NULL);
	char *result = (char *)malloc((ft_strlen_const(s) + 1) * sizeof(char));
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