/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:27:10 by adenny            #+#    #+#             */
/*   Updated: 2025/06/02 19:57:06 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(const char *str)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		nb = nb * 10 + (str[i++] - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && - nb < INT_MIN))
			return (0);
	}
	return (1);
}

int	has_duplicates(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;

	cur = a->top;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			if (cur->value == cmp->value)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	check_args(int ac)
{
	if (ac < 2)
		return (0);
	return (1);
}
