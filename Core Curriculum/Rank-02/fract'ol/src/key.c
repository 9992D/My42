/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:47:20 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 19:36:55 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	set_color(int keycode, t_fract *fract)
{
	if (keycode == KEY_1)
		fract->color = GREY;
	if (keycode == KEY_2)
		fract->color = PURPLE;
	if (keycode == KEY_3)
		fract->color = BLUE;
	if (keycode == KEY_4)
		fract->color = WHITE;
	if (keycode == KEY_5)
		fract->color = YELLOW;
	if (keycode == KEY_6)
		fract->color = BROWN;
	if (keycode == KEY_7)
		fract->color = PINK;
	if (keycode == KEY_8)
		fract->color = RED;
	if (keycode == KEY_9)
		fract->color = ORANGE;
}

void	move_image(int keycode, t_fract *fract)
{
	if (keycode == ARROW_LF)
		fract->movex += 0.5 * 1 / fract->scale;
	if (keycode == ARROW_RT)
		fract->movex -= 0.5 * 1 / fract->scale;
	if (keycode == ARROW_UP)
		fract->movey += 0.5 * 1 / fract->scale;
	if (keycode == ARROW_DN)
		fract->movey -= 0.5 * 1 / fract->scale;
}

void	change_iter(int keycode, t_fract *fract)
{
	if (keycode == KEY_MINUS)
	{
		if (fract->max > 100)
			fract->max /= 2;
	}
	if (keycode == KEY_PLUS)
	{
		if (fract->max < 1000)
			fract->max *= 2;
	}
}

int	key(int keycode, t_vars *data)
{
	if (keycode == KEY_ESC)
	{
		close_window(data);
		exit(0);
	}
	if (keycode == KEY_R)
	{
		data->img.fract.scale = 1.0;
		data->img.fract.movex = 0.0;
		data->img.fract.movey = 0.0;
		data->img.fract.max = 400;
		data->img.fract.color = GREEN;
	}
	if (keycode == KEY_C)
		data->img.fract.color_shift = !data->img.fract.color_shift;
	move_image(keycode, &data->img.fract);
	change_iter(keycode, &data->img.fract);
	set_color(keycode, &data->img.fract);
	return (0);
}

int	mouse(int button, int x, int y, t_vars *data)
{
	if (button == SCROLL_DN)
	{
		data->img.fract.movex -= ((x - WIDTH / 2.0) * 4.0 / WIDTH) * 1
			/ data->img.fract.scale;
		data->img.fract.movey -= ((y - HEIGHT / 2.0) * 4.0 / WIDTH) * 1
			/ data->img.fract.scale;
		data->img.fract.scale -= data->img.fract.scale * 0.5;
	}
	if (button == SCROLL_UP)
	{
		data->img.fract.movex += ((x - WIDTH / 2.0) * 4.0 / WIDTH) * 1
			/ data->img.fract.scale;
		data->img.fract.movey += ((y - HEIGHT / 2.0) * 4.0 / WIDTH) * 1
			/ data->img.fract.scale;
		data->img.fract.scale += data->img.fract.scale * 0.5;
	}
	return (0);
}
