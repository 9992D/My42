/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:00:54 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 11:22:26 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

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
		i++;
	}
	return ((int)(result * sign));
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	free(stack);
	return ;
}

int	find_index_for_chunk(t_stack *a, int boundary)
{
	int		index;
	t_node	*current;

	index = 0;
	current = a->top;
	while (current)
	{
		if (current->rank <= boundary)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*runner;

	current = a->top;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value == runner->value)
			{
				write(1, "Error\n", 6);
				return (1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}
