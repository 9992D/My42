#include "libft.h" 

void ft_putstr_fd(char *s, int fd)
{
    size_t k = 0; 

    if (!s) 
        return;
    while (s[k])
    {
        write(fd, &s[k], 1);
        k ++;
    }
}
