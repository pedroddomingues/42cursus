/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:49:09 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/24 16:00:58 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	print_parameters(t_fdf_params *fdf)
{
	char	*zoom;
	char	*z_multiplier;
	char	*color_mode;
	int		height;

	zoom = ft_itoa(fdf->zoom);
	z_multiplier = ft_ftoa(fdf->z_multiplier);
	if (fdf->color_mode == 0)
		color_mode = "SOLID";
	else if (fdf->color_mode == 1)
		color_mode = "GRADIENT";
	else
		color_mode = "RAINBOW";
	height = WIN_SIZE_Y - 30;
	mlx_string_put(fdf->mlx, fdf->win, 20, height, 0xFFFF00,
		"Zoom: ");
	mlx_string_put(fdf->mlx, fdf->win, 60, height, 0xFFFFFF, zoom);
	mlx_string_put(fdf->mlx, fdf->win, 130, height, 0xFFFF00,
		"Z multiplier: ");
	mlx_string_put(fdf->mlx, fdf->win, 230, height, 0xFFFFFF, z_multiplier);
	mlx_string_put(fdf->mlx, fdf->win, 300, height, 0xFFFF00,
		"Color mode: ");
	mlx_string_put(fdf->mlx, fdf->win, 390, height, 0xFFFFFF, color_mode);
	free(zoom);
	free(z_multiplier);
}

static void	print_movement_instructions(t_fdf_params *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, 0xFFFFFF,
		"W / ARROW UP ------- MOVE UP");
	mlx_string_put(fdf->mlx, fdf->win, 20, 195, 0xFFFFFF,
		"S / ARROW DOWN --- MOVE DOWN");
	mlx_string_put(fdf->mlx, fdf->win, 20, 210, 0xFFFFFF,
		"A / ARROW LEFT --- MOVE LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 225, 0xFFFFFF,
		"D / ARROW RIGHT - MOVE RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 240, 0xFFFFFF,
		"Q -------------- ROTATE LEFT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 255, 0xFFFFFF,
		"E ------------- ROTATE RIGHT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 300, 0xFFFFFF,
		"H - SHOW/HIDE THIS INSTRUCTIONS");
}

void	print_instructions(t_fdf_params *fdf)
{
	print_parameters(fdf);
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, 0xFFFF00, "-------"
		" INSTRUCTIONS:-------");
	mlx_string_put(fdf->mlx, fdf->win, 20, 75, 0xFFFFFF,
		"ESC ------------------- EXIT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 105, 0xFFFFFF,
		"+ ------------------ ZOOM IN");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0xFFFFFF,
		"- ----------------- ZOOM OUT");
	mlx_string_put(fdf->mlx, fdf->win, 20, 135, 0xFFFFFF,
		"C ------------- CHANGE COLOR");
	mlx_string_put(fdf->mlx, fdf->win, 20, 150, 0xFFFFFF,
		"J ---------- Z-MULTIPLIER UP");
	mlx_string_put(fdf->mlx, fdf->win, 20, 165, 0xFFFFFF,
		"K -------- Z-MULTIPLIER DOWN");
	print_movement_instructions(fdf);
}
