/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 23:27:01 by pehenriq          #+#    #+#             */
/*   Updated: 2021/11/01 23:45:01 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	if (!fdf)
	{
		free(fdf);
		error(fdf, 1);
	}
	if (argc == 1)
	{
		fdf->map.path = ft_strdup("maps/42.fdf");
		ft_printf("Using default map - maps/42.fdf\n");
		ft_printf("ALL MAPS SHOULD BE INSIDE 'maps' FOLDER\n");
		ft_printf("Usage: ./fdf [filepath]\n");
	}
	else
		fdf->map.path = ft_strdup(argv[1]);
}

void	error(t_fdf_params *fdf, int code)
{
	if (code == 1)
		ft_printf("Error creating fdf, try again.\n");
	else if (code == 2)
		ft_printf("Error to read the file. Make sure the path is correct.\n");
	else if (code == 3)
		ft_printf("Error to read the file. Make sure its a well formatted map");
	exit_program(fdf, code);
}
