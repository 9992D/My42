/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:46:31 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 19:37:07 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	set_type(int ac, char **av, t_fract *fract)
{
	if (!ft_strncmp(av[1], "j", 1))
	{
		if (ac != 4)
		{
			perror("Please add coordinates for Julia in your arguments");
			exit(1);
		}
		fract->type = 'j';
		fract->re_const = ft_atof(av[2]);
		fract->im_const = ft_atof(av[3]);
	}
	if (!ft_strncmp(av[1], "m", 1))
		fract->type = 'm';
	if (!ft_strncmp(av[1], "b", 1))
		fract->type = 'b';
}

void	print_inst(t_vars *data)
{
	mlx_string_put(data->mlx, data->win, 20, 30, WHITE, "Reset: R");
	mlx_string_put(data->mlx, data->win, 20, 60, WHITE, "Colors: 1 - 9");
	mlx_string_put(data->mlx, data->win, 20, 90, WHITE, "Iterations: + / -");
	mlx_string_put(data->mlx, data->win, 20, 120, WHITE, "Color Shift: C");
}

void	init_fract(t_fract *fract)
{
	fract->scale = 1.0;
	fract->movex = 0.0;
	fract->movey = 0.0;
	fract->max = 400;
	fract->re_const = 0.0;
	fract->im_const = 0.0;
	fract->color = GREEN;
	fract->color_shift = 0;
}

int	render_fract(t_vars *data)
{
	if (data->img.fract.color_shift)
	{
		data->img.fract.color += 5000;
		if (data->img.fract.color > 0xFFFFFF)
			data->img.fract.color = 1;
	}
	fract(&data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	print_inst(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	data;

	if (ac == 2 || ac == 4)
	{
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT,
				"Fractal Exploration");
		data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
		data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
				&data.img.line_length, &data.img.endian);
		init_fract(&data.img.fract);
		set_type(ac, av, &data.img.fract);
		mlx_loop_hook(data.mlx, &render_fract, &data);
		mlx_mouse_hook(data.win, &mouse, &data);
		mlx_key_hook(data.win, &key, &data);
		mlx_hook(data.win, 17, 0, close_window, &data);
		mlx_loop(data.mlx);
		return (0);
	}
	perror("Usage: ./fractol mandelbrot|julia|burningship (option) n1 n2");
	return (1);
}
