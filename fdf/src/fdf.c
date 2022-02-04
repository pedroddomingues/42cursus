/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 22:59:26 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/24 17:43:31 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	get_steps(t_fdf_params *fdf, t_point point1, t_point point2)
{
	float	max;
	float	x_step;
	float	y_step;

	x_step = point2.x - point1.x;
	y_step = point2.y - point1.y;
	if (fabs(x_step) > fabs(y_step))
		max = fabs(x_step);
	else
		max = fabs(y_step);
	x_step /= max;
	y_step /= max;
	fdf->x_step = x_step;
	fdf->y_step = y_step;
}

static void	draw_line(t_fdf_params *fdf, t_point point1, t_point point2)
{
	float	x_step;
	float	y_step;
	float	x;
	float	y;

	prepare_points(fdf, &point1);
	prepare_points(fdf, &point2);
	get_steps(fdf, point1, point2);
	x_step = fdf->x_step;
	y_step = fdf->y_step;
	x = point1.x;
	y = point1.y;
	while ((int)(x - point2.x) || (int)(y - point2.y))
	{
		if (point1.x <= WIN_SIZE_X && point2.y <= WIN_SIZE_Y
			&& point1.x >= 0 && point1.y >= 0)
			my_mlx_pixel_put(&(fdf->img), (int)x, (int)y,
				get_color(fdf, point1.z));
		x += x_step;
		y += y_step;
	}
}

static void	draw_lines_for_point(t_fdf_params *fdf, int x, int y)
{
	t_point	point1;
	t_point	point2;

	point1 = new_point(x, y, fdf->map.points[y][x], 0);
	if (x < fdf->map.y_max)
	{
		point2 = new_point(x + 1, y,
				fdf->map.points[y][x + 1], 0);
		draw_line(fdf, point1, point2);
	}
	if (y < fdf->map.x_max)
	{
		point2 = new_point(x, y + 1,
				fdf->map.points[y + 1][x], 0);
		draw_line(fdf, point1, point2);
	}
}

static void	print_lines(t_fdf_params *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y <= fdf->map.x_max)
	{
		x = 0;
		while (x <= fdf->map.y_max)
		{
			draw_lines_for_point(fdf, x, y);
			x++;
		}
		y++;
	}
}

void	print_fdf(t_fdf_params *fdf)
{
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	print_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
	if (fdf->instructions)
		print_instructions(fdf);
}
