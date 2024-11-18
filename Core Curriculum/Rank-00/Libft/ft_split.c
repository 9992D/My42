#include "libft.h"

size_t count_words(char const *s, char c)
{
    size_t count = 0;
    size_t k = 0;
    int indic = 0;

    while (s[k])
    {
        if (s[k] != c && indic == 0)
        {
            indic = 1;
            count ++;
        }
        else if (s[k] == c)
            indic = 0;
        k ++;
    }
    return count;
}

char *allocate(const char *start, size_t len)
{
    size_t k;

    char *word = (char *)malloc((len + 1) * sizeof(char));
    if (!word)
        return (NULL);
    k = 0;
    while(k < len)
    {
        word[k] = start[k];
        k ++;
    }
    word[k] = '\0';
    return (word);
    
}

void clean(char **result, size_t i)
{
    size_t k = 0;
    while (k < i)
    {
        free(result[k]);
        k++;
    }
    free(result);
}

char **ft_split(char const *s, char c)
{
    if (!s)
        return (NULL);
    char **result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!result)
        return (NULL);
    size_t i = 0;
    while (*s)
    {
        if (*s != c)
        {
            const char *start = s;
            size_t len = 0;
            while (*s && *s != c)
            {
                len++;
                s++;
            }
            result[i] = allocate(start, len);
            if (!result[i])
            {
                clean(result, i);
                return (NULL);
            }
            i++;
        }
        else
        {
            s++;
        }
    }
    result[i] = NULL;
    return result;
}
