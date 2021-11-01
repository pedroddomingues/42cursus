/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:22:09 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/30 23:42:00 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	fdf = malloc(sizeof(t_fdf_params));
	if (!fdf)
	{
		free(fdf);
		error(3, 0, "Error while creating fdf");
	}
	if (argc == 1)
	{
		fdf->map.map_name = ft_strdup("42");
		ft_printf("Using default map - 42.fdf\n");
		ft_printf("ALL MAPS SHOULD BE INSIDE 'maps' FOLDER\n");
		ft_printf("Usage: ./fdf [filename]\n");
	}
	else
		fdf->map.map_name = ft_strdup(argv[1]);
	return (fdf);
}

void	exit_program(t_fdf_params *fdf, int code)
{
	if (code == 0)
		ft_printf("Exiting program.");
	else if (code == 1)
		ft_printf("Error reading file: %s\n"
			"Make sure it exists in the maps folder.\n", fdf->map.path);
	else if (code == 2)
		ft_printf("Error reading file\n"
			"This file is not an fdf file.\n");
	if (code =! 1)
		mlx_destroy_image(fdf->mlx, fdf->img.ptr);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->angles);
	free(fdf->map.path);
	free(fdf->map.map_name);
	free(fdf->mlx);
	free(fdf);
	exit(code);
}
