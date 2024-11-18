#include "libft.h"

size_t count(int n)
{
    size_t count = 0;

    if (n <= 0)  
        count = 1;

    while (n != 0)
    {
        count++;
        n = n / 10;
    }
    return count;
}

char *ft_itoa(int n)
{
    size_t c = count(n);
    char *str = (char *)malloc((c + 1) * sizeof(char));
    if (!str)
        return (NULL);
    str[c] = '\0'; 
    if (n == 0) 
    {
        str[0] = '0';
        return str;
    }
    if (n < 0) 
    {
        str[0] = '-';
        if (n == INT_MIN) 
        {
            str[--c] = '8';
            n /= 10;
        }
        n = -n;
    }
    while (n > 0)
    {
        str[--c] = (n % 10) + '0';
        n = n / 10;
    }
    return str;
}
