/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenny <adenny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:47:45 by adenny            #+#    #+#             */
/*   Updated: 2025/06/03 19:53:14 by adenny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define KEY_ESC 65307
# define ARROW_LF 65363
# define ARROW_RT 65361
# define ARROW_DN 65362
# define ARROW_UP 65364
# define KEY_R 114
# define KEY_MINUS 45
# define KEY_PLUS 61
# define KEY_1 49
# define KEY_2 50
# define KEY_3 51
# define KEY_4 52
# define KEY_5 53
# define KEY_6 54
# define KEY_7 55
# define KEY_8 56
# define KEY_9 57
# define KEY_C 99

# define SCROLL_UP 4
# define SCROLL_DN 5

# define WIDTH 900
# define HEIGHT 700

# define WHITE 0xFFFFFF
# define GREY 0x808080
# define PURPLE 0x800080
# define BLUE 0xFF
# define GREEN 0x006400
# define YELLOW 0xFFFF00
# define BROWN 0x964B00
# define PINK 0xFFC0CB
# define RED 0xFF0000
# define ORANGE 0xFFA500
# define BLK 0x00

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fract
{
	double	scale;
	double	movex;
	double	movey;
	double	re_const;
	double	im_const;
	int		max;
	char	type;
	int		color;
	int		color_shift;
}			t_fract;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_fract	fract;
}			t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_img	img;
}			t_vars;

void		fract(t_img *img);
int			key(int keycode, t_vars *data);
int			mouse(int button, int x, int y, t_vars *data);
void		img_pixel_put(t_img *img, int x, int y, int color);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atof(const char *s);
int			close_window(t_vars *data);
void		cleanup(t_vars *data);
int			ft_isdigit(char c);
int			ft_bounded(int x, int y, int i, t_fract *fract);

#endif