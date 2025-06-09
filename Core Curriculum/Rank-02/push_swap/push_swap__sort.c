/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:09:20 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 15:11:17 by adenny           ###   ########.fr       */
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

void	rotate_to_index(t_stack *a, int index)
{
	int	i;

	i = 0;
	if (index <= a->size / 2)
	{
		while (i < index)
		{
			rotate(a);
			write(1, "ra\n", 3);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < a->size - index)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
			i++;
		}
	}
}

void	push_next_chunk_element(t_stack *a, t_stack *b, int boundary,
		int half_boundary)
{
	int	index;

	index = find_index_for_chunk(a, boundary);
	if (index != -1)
	{
		rotate_to_index(a, index);
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

void	compute_boundaries(int *params, double d_chunk_size, int *boundary,
		int *half_boundary)
{
	if (params[0] < params[1])
	{
		*boundary = (int)(params[0] * d_chunk_size);
		*half_boundary = (int)(params[0] * d_chunk_size - (d_chunk_size / 2));
	}
	else
	{
		*boundary = params[2] - 1;
		*half_boundary = params[2] - 1;
	}
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int num_chunks,
		double d_chunk_size)
{
	int	current_chunk;
	int	total;
	int	params[3];
	int	boundary;
	int	half_boundary;

	current_chunk = 1;
	total = a->size;
	while (a->size > 0)
	{
		params[0] = current_chunk;
		params[1] = num_chunks;
		params[2] = total;
		compute_boundaries(params, d_chunk_size, &boundary, &half_boundary);
		push_next_chunk_element(a, b, boundary, half_boundary);
		if (b->size >= (int)(current_chunk * d_chunk_size)
			&& current_chunk < num_chunks)
			current_chunk++;
	}
}
