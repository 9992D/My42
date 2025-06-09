/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:05:05 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 13:14:01 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_t_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_stack	*init_node_value(t_stack *stack, int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = -1;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
	}
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
	return (stack);
}

void	rank_init(t_stack *a)
{
	t_node *current = a->top;

	while (current)
	{
		int rank = 0;
		t_node *tmp = a->top;

		while (tmp)
		{
			if (tmp->value < current->value)
				rank++;
			tmp = tmp->next;
		}

		current->rank = rank;
		current = current->next;
	}
}

int	init_stacks(t_stack **a, t_stack **b)
{
	*a = init_t_stack();
	*b = init_t_stack();
	if (!*a || !*b)
	{
		write(1, "Error\n", 6);
		if (*a)
			free_stack(*a);
		if (*b)
			free_stack(*b);
		return (0);
	}
	return (1);
}

int	fill_stack(t_stack **a, t_stack *b, int ac, char **av)
{
	while (ac > 1)
	{
		*a = init_node_value(*a, ft_atoi(av[ac - 1]));
		if (!*a)
		{
			write(1, "Error\n", 6);
			free_stack(b);
			return (0);
		}
		ac--;
	}
	return (1);
}
