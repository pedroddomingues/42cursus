/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 22:28:33 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/24 17:17:44 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	print_lines(t_fdf_params *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y <= fdf->map.height + 1)
	{
		x = 0;
		while (x <= fdf->map.width)
		{
			if (x < fdf->map.width)
				draw_line(fdf, x, y, x + 1, y);
			if (y <= fdf->map.height)
				draw_line(fdf, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

void	draw_fdf(t_fdf_params *fdf)
{
	fdf->img.ptr = mlx_new_image(fdf->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.ptr, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	print_lines(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.ptr, 0, 0);
}

void	reset_image(t_fdf_params *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	// mlx_clear_window(fdf->mlx, fdf->win);
	draw_fdf(fdf);
}
