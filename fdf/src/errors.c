/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:43:31 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/13 21:35:18 by pehenriq         ###   ########.fr       */
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
		fdf->map.path = ft_strdup(argv[1]);
	if (!fdf->map.path)
		error(3, 0, "Error while allocating memory for file name.");
	return (fdf);
}
