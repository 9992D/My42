/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__init.C                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:05:05 by adenny            #+#    #+#             */
/*   Updated: 2025/03/04 07:19:07 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_t_stack(void) 
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    return (stack);
}

t_stack *init_node_value(t_stack *stack, int value)
{
    t_node *node; 

    node = malloc(sizeof(t_node));
    if (!node) // il faut que je free ici car si le n-ème malloc fail, j'ai des leaks 
        return (NULL);
    node->value = value;
    node->rank = -1; // -1 = not yet ranked
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

void rank_init(t_stack *a)
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