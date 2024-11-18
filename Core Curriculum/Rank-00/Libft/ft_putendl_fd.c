#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    if (!s) 
        return;

    size_t i = 0;
    while (s[i]) 
    {
        write(fd, &s[i], 1);
        i++;
    }
    write(fd, "\n", 1); 
}
