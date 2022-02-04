/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:43:31 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/23 10:21:11 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	if (argc == 1)
	{
		fdf->map.map_name = ft_strdup("42");
		ft_printf("Using default map - 42.fdf\n");
		ft_printf("ALL MAPS SHOULD BE INSIDE 'maps' FOLDER\n");
		ft_printf("Usage: ./fdf [filename]\n");
	}
	else
		fdf->map.map_name = ft_strdup(argv[1]);
	if (!fdf->map.map_name)
		error(3, 0, "Error while allocating memory for file name.");
	return (fdf);
}
