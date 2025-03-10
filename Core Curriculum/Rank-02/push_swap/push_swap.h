/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:51:20 by adenny            #+#    #+#             */
/*   Updated: 2025/03/04 10:48:40 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
    int value;
    int rank;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

int	ft_atoi(const char *str);
t_stack *init_t_stack(void);
t_stack *init_node_value(t_stack *stack, int value);
void rank_init(t_stack *a);
void free_stack(t_stack *stack);
int swap(t_stack *stack);
int push(t_stack *a, t_stack *b);
int rotate(t_stack *a);
int reverse_rotate(t_stack *a);