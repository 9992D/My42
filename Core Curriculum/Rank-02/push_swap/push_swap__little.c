/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__little.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:04:52 by adenny            #+#    #+#             */
/*   Updated: 2025/06/02 20:09:07 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->value;
	s = a->top->next->value;
	t = a->top->next->next->value;
	if (f > s && s < t && f < t)
		case_1(a);
	else if (f > s && s > t)
		case_2(a);
	else if (f > s && s < t && f > t)
		case_3(a);
	else if (f < s && s > t && f < t)
		case_4(a);
	else if (f < s && s > t && f > t)
		case_5(a);
}

int	find_index_by_rank(t_stack *a, int rank)
{
	t_node	*current;
	int		index;

	index = 0;
	current = a->top;
	while (current)
	{
		if (current->rank == rank)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	find_min_rank(t_stack *a)
{
	t_node	*current;
	int		min_rank;

	current = a->top;
	min_rank = current->rank;
	while (current)
	{
		if (current->rank < min_rank)
			min_rank = current->rank;
		current = current->next;
	}
	return (min_rank);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	min_rank;

	while (a->size > 3)
	{
		min_rank = find_min_rank(a);
		rotate_to_index(a, find_index_by_rank(a, min_rank));
		push(a, b);
		write(1, "pb\n", 3);
	}
	sort_three(a);
	if (b->size > 1 && b->top->rank < b->top->next->rank)
	{
		swap(b);
		write(1, "sb\n", 3);
	}
	while (b->size > 0)
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
}
