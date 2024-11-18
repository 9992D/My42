#include "libft.h"

int	ft_atoi(const char *str)
{
    int i;
    int sign;
    long result;

    i = 0;
    sign = 1;
    result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
        || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (result * sign > INT_MAX)
            return (INT_MAX);
        if (result * sign < INT_MIN)
            return (INT_MIN);
        i++;
    }
    return ((int)(result * sign));
}