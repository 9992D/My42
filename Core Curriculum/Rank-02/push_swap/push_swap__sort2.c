/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__sort2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:10:55 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 15:14:39 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b_to_max(t_stack *b, int max_pos)
{
	int	i;

	i = 0;
	if (max_pos <= b->size / 2)
	{
		while (i < max_pos)
		{
			rotate(b);
			write(1, "rb\n", 3);
			i++;
		}
	}
	else
	{
		while (i < b->size - max_pos)
		{
			reverse_rotate(b);
			write(1, "rrb\n", 4);
			i++;
		}
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int		max_rank;
	int		pos;
	int		max_pos;
	t_node	*tmp;

	while (b->size > 0)
	{
		max_rank = -1;
		pos = 0;
		max_pos = 0;
		tmp = b->top;
		while (tmp)
		{
			if (tmp->rank > max_rank)
			{
				max_rank = tmp->rank;
				max_pos = pos;
			}
			pos++;
			tmp = tmp->next;
		}
		rotate_b_to_max(b, max_pos);
		push(b, a);
		write(1, "pa\n", 3);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int		num_chunks;
	double	d_chunk_size;

	init_chunk_params(a, &num_chunks, &d_chunk_size);
	push_chunks_to_b(a, b, num_chunks, d_chunk_size);
	push_back_to_a(a, b);
}

int	exit_and_cleanup(t_stack *a, t_stack *b, int status)
{
	free_stack(a);
	free_stack(b);
	return (status);
}
