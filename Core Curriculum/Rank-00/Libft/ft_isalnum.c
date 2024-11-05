#include "libft.h"

int	ft_isalnum(int character)
{
	if (ft_isalpha(character) == 1 || ft_isdigit(character) == 1)
	{
		return (1);
	}
	return (0);
}