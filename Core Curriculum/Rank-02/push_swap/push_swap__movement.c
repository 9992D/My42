/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:15:31 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 15:12:04 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
	return (1);
}

int	push(t_stack *a, t_stack *b)
{
	t_node	*top_a;

	if (a->size == 0)
		return (0);
	top_a = a->top;
	a->top = top_a->next;
	if (b->size == 0)
	{
		b->top = top_a;
		b->bottom = top_a;
		top_a->next = NULL;
	}
	else
	{
		top_a->next = b->top;
		b->top = top_a;
	}
	a->size--;
	b->size++;
	if (a->size == 0)
		a->bottom = NULL;
	return (1);
}

int	rotate(t_stack *a)
{
	t_node	*top_a;

	if (a->size < 2)
		return (0);
	top_a = a->top;
	a->top = top_a->next;
	a->bottom->next = top_a;
	a->bottom = top_a;
	a->bottom->next = NULL;
	return (1);
}

int	reverse_rotate(t_stack *a)
{
	t_node	*new_bottom;

	if (a->size < 2)
		return (0);
	new_bottom = a->top;
	while (new_bottom->next != a->bottom)
		new_bottom = new_bottom->next;
	a->bottom->next = a->top;
	a->top = a->bottom;
	a->bottom = new_bottom;
	a->bottom->next = NULL;
	return (1);
}
