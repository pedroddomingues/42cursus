/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:43:31 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/20 14:06:10 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("WE ENCOURAGE ALL MAPS SHOULD BE INSIDE 'maps' FOLDER\n");
		ft_printf("Usage: ./fdf [file]\n");
		exit_program(fdf, 1);
	}
	else
	{
		if (ft_strendcmp(argv[1], ".fdf"))
			exit_program(fdf, 1);
		fdf->map.path = ft_strdup(argv[1]);
	}
	if (!fdf->map.path)
		exit_program(fdf, 1);
	return (fdf);
}
