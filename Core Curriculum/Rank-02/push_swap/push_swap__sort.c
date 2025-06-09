/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:09:20 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 11:18:20 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_chunk_params(t_stack *a, int *num_chunks, double *d_chunk_size)
{
	int	total;

	total = a->size;
	if (total < 500)
		*num_chunks = 5;
	else
		*num_chunks = 10;
	*d_chunk_size = (double)total / *num_chunks;
}

void	push_next_chunk_element(t_stack *a, t_stack *b, int boundary,
		int half_boundary)
{
	int	index;

	index = find_index_for_chunk(a, boundary);
	if (index != -1)
	{
		if (index <= a->size / 2)
			for (int i = 0; i < index; i++)
			{
				rotate(a);
				write(1, "ra\n", 3);
			}
		else
			for (int i = 0; i < a->size - index; i++)
			{
				reverse_rotate(a);
				write(1, "rra\n", 4);
			}
		push(a, b);
		write(1, "pb\n", 3);
		if (b->size > 1 && b->top->rank < half_boundary)
		{
			rotate(b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int num_chunks,
		double d_chunk_size)
{
	int	current_chunk;
	int	total;
	int	boundary;
	int	half_boundary;

	current_chunk = 1;
	total = a->size;
	while (a->size > 0)
	{
		boundary = (current_chunk < num_chunks) ? (int)(current_chunk
				* d_chunk_size) : (total - 1);
		half_boundary = (current_chunk < num_chunks) ? (int)(current_chunk
				* d_chunk_size - (d_chunk_size / 2)) : (total - 1);
		push_next_chunk_element(a, b, boundary, half_boundary);
		if (b->size >= (int)(current_chunk * d_chunk_size)
			&& current_chunk < num_chunks)
			current_chunk++;
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int		max_rank = -1, pos = 0, max_pos;
	t_node	*tmp;

	while (b->size > 0)
	{
		max_rank = -1, pos = 0, max_pos = 0;
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
		if (max_pos <= b->size / 2)
			for (int i = 0; i < max_pos; i++)
			{
				rotate(b);
				write(1, "rb\n", 3);
			}
		else
			for (int i = 0; i < b->size - max_pos; i++)
			{
				reverse_rotate(b);
				write(1, "rrb\n", 4);
			}
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
