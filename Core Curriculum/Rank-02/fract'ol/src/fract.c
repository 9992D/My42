/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:46:56 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 20:05:14 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	bship(double c1, double c2, t_fract *fract)
{
	int		i;
	double	x;
	double	y;
	double	t;

	x = 0.0;
	y = 0.0;
	t = 0.0;
	i = 0;
	while (ft_bounded(x, y, i, fract))
	{
		t = fabs(x) * fabs(x) - fabs(y) * fabs(y) + c1;
		y = 2 * fabs(x) * fabs(y) + c2;
		x = t;
		i++;
	}
	return (i);
}

int	jul(double c1, double c2, t_fract *fract)
{
	int		i;
	double	x;
	double	y;
	double	t;

	x = c1;
	y = c2;
	t = 0.0;
	i = 0;
	while (ft_bounded(x, y, i, fract))
	{
		t = x * x - y * y + fract->re_const;
		y = 2 * x * y + fract->im_const;
		x = t;
		i++;
	}
	return (i);
}

int	mbrot(double c1, double c2, t_fract *fract)
{
	int		i;
	double	x;
	double	y;
	double	t;

	x = 0.0;
	y = 0.0;
	t = 0.0;
	i = 0;
	while (ft_bounded(x, y, i, fract))
	{
		t = x * x - y * y + c1 - 0.3;
		y = 2 * x * y + c2;
		x = t;
		i++;
	}
	return (i);
}

void	draw(int row, int col, t_img *img)
{
	double	c_re;
	double	c_im;
	int		i;

	i = 0;
	c_re = ((col - WIDTH / 2.0) * 4.0 / WIDTH) * (1 / (img->fract.scale))
		+ img->fract.movex;
	c_im = ((row - HEIGHT / 2.0) * 4.0 / WIDTH) * (1 / img->fract.scale)
		+ img->fract.movey;
	if (img->fract.type == 'm')
		i = mbrot(c_re, c_im, &img->fract);
	if (img->fract.type == 'j')
		i = jul(c_re, c_im, &img->fract);
	if (img->fract.type == 'b')
		i = bship(c_re, c_im, &img->fract);
	if (i < img->fract.max)
		img_pixel_put(img, col, row, img->fract.color * i / (img->fract.max
				/ 20));
	else
		img_pixel_put(img, col, row, BLK);
}

void	fract(t_img *img)
{
	int	row;
	int	col;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			draw(row, col, img);
			col++;
		}
		row++;
	}
}
