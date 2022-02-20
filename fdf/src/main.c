/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:39:21 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/19 02:48:15 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	close_window(t_fdf_params *fdf)
{
	exit_program(fdf, 0);
	return (0);
}

static void	new_window(t_fdf_params *fdf, char *name)
{
	fdf->win = mlx_new_window(fdf->mlx, WIN_SIZE_X, WIN_SIZE_Y, name);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}

static void	init(t_fdf_params *fdf)
{
	fdf->mlx = mlx_init();
	new_window(fdf, "fdf - pehenriq");
	fdf->angles = malloc(sizeof(t_angles));
	if (!fdf->angles)
		exit_program(fdf, 1);
	fdf->angles->alpha = 1.05;
	fdf->angles->beta = 0.65;
	fdf->zoom = 50;
	fdf->translation_x = 400;
	fdf->translation_y = 100;
	fdf->map.x_max = -1;
	fdf->map.y_max = 0;
	fdf->map.z_min = 0;
	fdf->map.z_max = 0;
	fdf->map.x = 0;
	fdf->instructions = 0;
	fdf->color_mode = 0;
	fdf->color_one = create_trgb(255, 255, 255, 255);
	fdf->color_two = create_trgb(255, 255, 255, 0);
	ft_printf("\n\nPRESS H TO SHOW INSTRUCTIONS AND STATUS\n\n");
	load_map(fdf);
}

int	main(int argc, char **argv)
{
	t_fdf_params	*fdf;

	fdf = malloc(sizeof(t_fdf_params));
	if (!fdf)
	{
		perror("Error\n");
		exit(1);
	}
	check_initial_errors(fdf, argc, argv);
	init(fdf);
	print_fdf(fdf);
	mlx_key_hook(fdf->win, &key_hook, fdf);
	mlx_loop(fdf->mlx);
}
