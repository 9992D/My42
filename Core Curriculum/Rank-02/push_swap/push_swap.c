/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:52:07 by adenny            #+#    #+#             */
/*   Updated: 2025/05/28 13:11:06 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac)
{
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_initial_conditions(int ac, char **av)
{
	if (!check_args(ac))
		return (0);
	if (!has_only_numbers(ac, av))
		return (0);
	if (ac == 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	prepare_stack_a(t_stack **a, t_stack **b, int ac, char **av)
{
	if (!fill_stack(a, *b, ac, av))
		return (0);
	if (has_duplicates(*a))
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	if (is_sorted(*a))
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_initial_conditions(ac, av))
		return (1);
	if (!init_stacks(&a, &b))
		return (1);
	if (!prepare_stack_a(&a, &b, ac, av))
		return (1);
	rank_init(a);
	chunk_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
