/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:47:05 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 19:32:47 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;
	int				count;

	i = 0;
	count = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	if (n == 0 || (a == 0 && b == 0))
		return (0);
	while (i < n && (a[i] != '\0' || b[i] != '\0'))
	{
		if (a[i] != b[i])
		{
			count += a[i] - b[i];
			break ;
		}
		i++;
	}
	return (count);
}

static double	parse_digits(const char **ps, int *e)
{
	double	val;
	int		c;

	val = 0.0;
	*e = 0;
	c = **ps;
	while (c != '\0' && ft_isdigit(c))
	{
		val = val * 10.0 + (c - '0');
		(*ps)++;
		c = **ps;
	}
	if (**ps == '.')
	{
		(*ps)++;
		c = **ps;
		while (c != '\0' && ft_isdigit(c))
		{
			val = val * 10.0 + (c - '0');
			*e -= 1;
			(*ps)++;
			c = **ps;
		}
	}
	return (val);
}

double	ft_atof(const char *s)
{
	double	a;
	int		e;
	int		neg;

	if (!s)
		return (0.0);
	neg = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			neg = -1;
	a = parse_digits(&s, &e);
	return (neg * a * pow(10.0, e));
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

int	close_window(t_vars *data)
{
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
