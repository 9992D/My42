#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(char *str);
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *__restrict__ dest, const void *__restrict__ src,
			size_t count);
void	ft_memmove(void *dest, const void *src, size_t count);
char	*strlcpy(char *string1, const char *string2, size_t count);

#endif
