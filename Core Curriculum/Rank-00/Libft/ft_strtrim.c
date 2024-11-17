#include <stdlib.h>

size_t ft_len(const char *str)
{
    size_t len = 0;

    while (str[len])
        len++;
    return len;
}

int is_it_in(char c, const char *set)
{
    size_t k = 0;

    while (set[k])
    {
        if (set[k] == c)
            return (1);
        k ++;
    }
    return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    size_t len_s1;
    char *new_s1;

    if (!s1 || !set)
        return (NULL);
    len_s1 = ft_len(s1);
    start = 0;
    while (s1[start] && is_it_in(s1[start], set) == 1)
        start ++;
    end = len_s1;
    while (end > start && is_it_in(s1[end - 1], set))
        end --;
    new_s1 = (char *)malloc((end - start + 1) * sizeof(char));
    if (!new_s1)
        return (NULL);
    size_t i = 0;
    while (start < end)
    {
        new_s1[i] = s1[start];
        start ++;
        i ++;
    }
    new_s1[i] = '\0';
    return (new_s1);
}