#include "libft.h"

size_t ft_strlen(const char *str)
{
    size_t len = 0;

    while (str[len])
        len++;
    return (len);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *joined_str;
    size_t s1_len;
    size_t s2_len;
    size_t i;
    size_t j;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    joined_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
    if (!joined_str)
        return (NULL);
    i = 0;
    while (i < s1_len)
    {
        joined_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (j < s2_len)
    {
        joined_str[i + j] = s2[j];
        j++;
    }
    joined_str[i + j] = '\0';
    return (joined_str);
}
