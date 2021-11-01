/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:11:26 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/25 22:58:03 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_point	set_point(float x, float y, float z)
{
	t_point	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (x <= WIN_SIZE_X && y <= WIN_SIZE_Y)
		*(unsigned int *) dst = color;
}

int	shade(int color1, int color2)
{
	static int	alpha;
	int			r1;
	int			g1;
	int			b1;
	int			r2;
	int			g2;
	int			b2;

	r1 = get_r(color1);
	g1 = get_g(color1);
	b1 = get_b(color1);
	r2 = get_r(color2);
	g2 = get_g(color2);
	b2 = get_b(color2);
	alpha += 2;
	return (create_trgb(255, r1 + (r2-r1)*alpha, g1 + (g2 - g1)*alpha, b1 + (b2 - b1)*alpha));
}

int	rainbow(void)
{
	static int	case_number;
	static int	ascending;
	static int	descending;

	ascending += 11;
	if (ascending > 255)
	{
		case_number++;
		ascending = 0;
	}
	if (case_number > 5)
		case_number = 0;
	descending = 255 - ascending;
	if (case_number == 0)
		return (create_trgb(255, 255, ascending, 0));
	else if (case_number == 1)
		return (create_trgb(255, descending, 255, 0));
	else if (case_number == 2)
		return (create_trgb(255, 0, 255, ascending));
	else if (case_number == 3)
		return (create_trgb(255, 0, descending, 255));
	else if (case_number == 4)
		return (create_trgb(255, ascending, 0, 255));
	else
		return (create_trgb(255, ascending, 0, 255));
}

void	zoom(t_fdf_params *fdf, float *x, float *y)
{
	*x *= fdf->zoom;
	*y *= fdf->zoom;
}

void	projection(t_fdf_params *fdf, float *x, float *y, int z)
{
	*x = (*x - *y) * cos(fdf->angles->alpha);
	*y = (*x + *y) * sin(fdf->angles->beta) - z;
}

void	translate(t_fdf_params *fdf, float *x, float *y)
{
	*x += fdf->translation_x;
	*y += fdf->translation_y;
}

void	draw_line(t_fdf_params *fdf, float x, float y, float x1, float y1)
{
	float	x_step;
	float	y_step;
	float	max;
	int		z;
	int		z1;
	int		color;

	z = fdf->map.map[(int)y][(int)x];
	z1 = fdf->map.map[(int)y1][(int)x1];
	zoom(fdf, &x, &y);
	zoom(fdf, &x1, &y1);
	projection(fdf, &x, &y, z);
	projection(fdf, &x1, &y1, z1);
	translate(fdf, &x, &y);
	translate(fdf, &x1, &y1);
	if (z || z1)
		color = rainbow();
	else
		color = 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	if (fabs(x_step) > fabs(y_step))
		max = fabs(x_step);
	else
		max = fabs(y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x <= WIN_SIZE_X && y <= WIN_SIZE_Y)
			my_mlx_pixel_put(&(fdf->img), x, y, color);
		x += x_step;
		y += y_step;
	}
}

float	to_rad(int degree)
{
	return (degree * PI / 180);
}
