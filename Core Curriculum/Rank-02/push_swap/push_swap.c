/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:52:07 by adenny            #+#    #+#             */
/*   Updated: 2025/06/09 23:19:08 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_and_convert(char *arg, t_stack **a, t_stack *b)
{
	int	value;

	if (!is_valid_number(arg))
	{
		write(1, "Error\n", 6);
		free_stack(*a);
		free_stack(b);
		return (0);
	}
	value = ft_atoi(arg);
	*a = init_node_value(*a, value);
	if (!*a)
	{
		write(1, "Error\n", 6);
		free_stack(b);
		return (0);
	}
	return (1);
}

int	parse_and_fill_stack(t_stack **a, t_stack *b, int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (!validate_and_convert(av[i], a, b))
			return (0);
		i--;
	}
	return (1);
}

int	check_and_prepare(t_stack **a, t_stack **b, int ac, char **av)
{
	if (!check_args(ac))
		return (0);
	if (!init_stacks(a, b))
		return (0);
	if (!parse_and_fill_stack(a, *b, ac, av))
		return (0);
	if (has_duplicates(*a))
	{
		free_stack(*a);
		free_stack(*b);
		return (0);
	}
	return (1);
}

int	prepare_args(int ac, char **av, char ***args, int *args_count)
{
	if (ac == 2)
	{
		*args = ft_split(av[1], ' ');
		if (!*args || !**args)
		{
			free_array(*args, count_words(av[1], ' '));
			write(1, "Error\n", 6);
			return (0);
		}
		*args_count = count_words(av[1], ' ');
	}
	else if (ac > 2)
	{
		*args = &av[1];
		*args_count = ac - 1;
	}
	else
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		args_count;
	int		free_args;

	a = NULL;
	b = NULL;
	if (!prepare_args(ac, av, &args, &args_count))
		return (1);
	free_args = (ac == 2);
	if (!check_and_prepare(&a, &b, args_count + 1, args - 1))
	{
		if (free_args)
			free_array(args, args_count);
		return (1);
	}
	if (free_args)
	{
		free_array(args, args_count);
		return (run_push_swap(a, b));
	}
	return (run_push_swap(a, b));
}
