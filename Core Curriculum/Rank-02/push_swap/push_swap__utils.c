/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:00:54 by adenny            #+#    #+#             */
/*   Updated: 2025/03/04 10:48:37 by adenny           ###   ########.fr       */
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

void free_stack(t_stack *stack)
{
    if (!stack)
        return;
        
    t_node *current = stack->top;
    t_node *tmp;

    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(stack);
    return;
}

/*
Goal: swap the first two elements at the top of stack. Do nothing if there is only one or no elements.
Return: 1 if swap is successful, 0 otherwise.
*/

int swap(t_stack *stack)
{
    if (stack->size < 2)
        return (0);

    t_node *first = stack->top;
    t_node *second = first->next;

    first->next = second->next;
    second->next = first;
    stack->top = second;

    if (stack->size == 2)
        stack->bottom = first;

    return (1);
}

/*
Goal: push the first element at the top of stack a to the top of stack b. Do nothing if stack a is empty.
Return: 1 if push is successful, 0 otherwise.
*/

int push(t_stack *a, t_stack *b)
{
    if (a->size == 0)
        return (0);

    t_node *top_a = a->top; 
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

/*
Goal: rotate the stack by moving up all elements by one. The first element becomes the last one.
Return: 1 if rotate is successful, 0 otherwise.
*/

int rotate(t_stack *a)
{
    if (a->size < 2)
        return (0);

    t_node *top_a = a->top;
    a->top = top_a->next;
    a->bottom->next = top_a;
    a->bottom = top_a; 
    a->bottom->next = NULL;

    return (1);
}

/*
Goal: reverse rotate the stack by moving down all elements by one. The last element becomes the first one.
Return: 1 if reverse rotate is successful, 0 otherwise. 
*/

int reverse_rotate(t_stack *a)
{
    if (a->size < 2)
        return (0);

    t_node *new_bottom = a->top;
    while (new_bottom->next != a->bottom)
        new_bottom = new_bottom->next;

    a->bottom->next = a->top;
    a->top = a->bottom;
    a->bottom = new_bottom;
    a->bottom->next = NULL;

    return (1);
}