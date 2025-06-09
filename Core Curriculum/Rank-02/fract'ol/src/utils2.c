/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 19:24:22 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 19:32:17 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_bounded(int x, int y, int i, t_fract *fract)
{
	return (x * x + y * y <= 4 && i < fract->max);
}
