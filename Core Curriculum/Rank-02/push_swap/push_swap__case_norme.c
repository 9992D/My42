/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__case_norme.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 20:06:34 by adenny            #+#    #+#             */
/*   Updated: 2025/06/02 20:06:40 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_1(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	case_2(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	case_3(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	case_4(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
	rotate(a);
	write(1, "ra\n", 3);
}

void	case_5(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
