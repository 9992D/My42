/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:52:07 by adenny            #+#    #+#             */
/*   Updated: 2025/03/04 18:13:47 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_stack *a, t_stack *b)
{
    int max_bits = 0;
    int max_num = a->size - 1;
    
    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (int i = 0; i < max_bits; i++)
    {
        int size = a->size;
        
        for (int j = 0; j < size; j++)
        {
            if (((a->top->rank >> i) & 1) == 0)
            {
                push(a, b);
                write(1, "pb\n", 3);
            }
            else
            {
                rotate(a);
                write(1, "ra\n", 3);
            }
        }

        while (b->size > 0)
        {
            push(b, a);
            write(1, "pa\n", 3);
        }
    }
}
    
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    if (ac < 2)
    {
        write(1, "Error\n", 6);
        return (0);
    }
    a = init_t_stack();
    b = init_t_stack();
    if (!a || !b) // pas suffisant, il faut que je free a ou b
    {
        write(1, "Error\n", 6);
        return (1);
    }
    while (ac > 1)
    {
        a = init_node_value(a, ft_atoi(av[ac - 1]));
        if (!a)
        {
            write(1, "Error\n", 6);
            return (1);
        }
        ac--;
    }
    rank_init(a);
    radix_sort(a, b);
    free_stack(a);
    free_stack(b);
    return (0);
}
