/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:08:08 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/24 17:24:16 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	zoom(t_fdf_params *fdf, float *x, float *y)
{
	*x *= fdf->zoom;
	*y *= fdf->zoom;
}

static void	projection(t_fdf_params *fdf, float *x, float *y, int z)
{
	*x = (*x - *y) * cos(fdf->angles->alpha);
	*y = (*x + *y) * sin(fdf->angles->beta) - (float) z;
}

static void	translate(t_fdf_params *fdf, float *x, float *y)
{
	*x += fdf->translation_x;
	*y += fdf->translation_y;
}

void	prepare_points(t_fdf_params *fdf, t_point *point)
{
	float	x;
	float	y;
	int		z;

	x = point->x;
	y = point->y;
	z = point->z;
	zoom(fdf, &x, &y);
	projection(fdf, &x, &y, z);
	translate(fdf, &x, &y);
	point->x = x;
	point->y = y;
}

t_point	new_point(float x, float y, int z, int color)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = color;
	return (point);
}
