#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t c = 0;

    if (n == 0)
        return 0;
    while (c < n && s1[c] && s2[c])
    {
        if (s1[c] != s2[c])
            return (s1[c] - s2[c]);
        c ++;
    }
    return (0);
}
