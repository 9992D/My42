#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t c;
    unsigned char	*ptr1;
    unsigned char	*ptr2;

    c = 0;
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    while (c < n)
    {
        if (ptr1[c] != ptr2[c])
            return (ptr1[c] - ptr2[c]);
        c ++;
    }
    return 0;
}
