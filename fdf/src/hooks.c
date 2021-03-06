/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:53:01 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/19 02:45:52 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	reset_image(t_fdf_params *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	print_fdf(fdf);
}

static void	change_color_mode(t_fdf_params *fdf)
{
	fdf->color_mode++;
	if (fdf->color_mode > 2)
		fdf->color_mode = 0;
}

static void	toggle_instructions(t_fdf_params *fdf)
{
	fdf->instructions++;
	if (fdf->instructions > 1)
		fdf->instructions = 0;
}

int	key_hook(int key, t_fdf_params *fdf)
{
	if (key == KEY_ESC)
		exit_program(fdf, 0);
	else if (key == KEY_ARROW_LEFT || key == KEY_A)
		fdf->translation_x += 40;
	else if (key == KEY_ARROW_UP || key == KEY_W)
		fdf->translation_y += 40;
	else if (key == KEY_ARROW_RIGHT || key == KEY_D)
		fdf->translation_x -= 40;
	else if (key == KEY_ARROW_DOWN || key == KEY_S)
		fdf->translation_y -= 40;
	else if (key == KEY_PLUS)
		fdf->zoom += 10;
	else if (key == KEY_MINUS)
		fdf->zoom -= 10;
	else if (key == KEY_C)
		change_color_mode(fdf);
	else if (key == KEY_H)
		toggle_instructions(fdf);
	reset_image(fdf);
	return (0);
}
