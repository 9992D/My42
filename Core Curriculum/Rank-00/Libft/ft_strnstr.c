#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t c;
    size_t k;

    if (*needle == '\0')
        return ((char *)haystack);

    c = 0;
    while (haystack[c] && c < len)
    {
        if (haystack[c] == needle[0])
        {
            k = 0;
            while (c + k < len && haystack[c + k] && needle[k] && haystack[c + k] == needle[k])
            {
                k++;
                if (needle[k] == '\0')
                    return ((char *)&haystack[c]);
            }
        }
        c++;
    }
    return (NULL);
}