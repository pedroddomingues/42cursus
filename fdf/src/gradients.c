/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:14:15 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/08 19:30:30 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	rainbow(void)
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

static int	gradient(t_fdf_params *fdf, int z)
{
	float	percent;
	float	r;
	float	g;
	float	b;

	percent = ((z - fdf->map.z_min) * 100 / (fdf->map.z_max - fdf->map.z_min));
	r = get_r(fdf->color_one) + percent
		* (get_r(fdf->color_two) - get_r(fdf->color_one));
	g = get_g(fdf->color_one) + percent
		* (get_g(fdf->color_two) - get_g(fdf->color_one));
	b = get_b(fdf->color_one) + percent
		* (get_b(fdf->color_two) - get_b(fdf->color_one));
	return (create_trgb(255, (int)r, (int)g, (int)b));
}

int	get_color(t_fdf_params *fdf, int z)
{
	if (fdf->color_mode == SOLID)
	{
		if (z > (fdf->map.z_min + fdf->map.z_max) / 2)
			return (fdf->color_two);
		return (fdf->color_one);
	}
	else if (fdf->color_mode == GRADIENT)
		return (gradient(fdf, z));
	else
		return (rainbow());
}
