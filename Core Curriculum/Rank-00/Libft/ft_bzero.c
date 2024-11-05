#include <stddef.h>

void ft_bzero(void* s, size_t n)
{
    unsigned char *p = (unsigned char *)s;
    while (n > 0)
    {
        *p = 0;
        n --;
        p ++;
    }
}