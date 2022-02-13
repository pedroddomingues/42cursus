/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:01:12 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/13 21:31:11 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	get_map_size(t_fdf_params *fdf, int fd)
{
	char	**split;
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	if (split[0] == NULL)
		error(2, 0, "Error while reading file.");
	while (split[y])
		y++;
	fdf->map.y_max = y - 1;
	ft_free_split(split);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		fdf->map.x_max++;
	}
	free(line);
}

static void	map_malloc(t_fdf_params *fdf, int fd)
{
	int		i;

	i = 0;
	get_map_size(fdf, fd);
	fdf->map.points = (int **)malloc(sizeof(int *) * (fdf->map.x_max + 1));
	if (!fdf->map.points)
		error(1, 0, "Error while allocating memory.");
	fdf->map.colors = (int **)malloc(sizeof(int *) * (fdf->map.x_max + 1));
	if (!fdf->map.colors)
		error(1, 0, "Error while allocating memory.");
	while (i <= fdf->map.x_max)
	{
		fdf->map.points[i] = (int *)malloc(sizeof(int) * (fdf->map.y_max + 1));
		if (!fdf->map.points[i])
			error(1, 0, "Error while allocating memory.");
		fdf->map.colors[i] = (int *)malloc(sizeof(int) * (fdf->map.y_max + 1));
		if (!fdf->map.colors[i])
			error(1, 0, "Error while allocating memory.");
		i++;
	}
}

static void	parse_line(t_fdf_params *fdf, char *line)
{
	char	**line_split;
	char	**color_split;
	int		y;
	int		z;

	y = 0;
	line_split = ft_split(line, ' ');
	while (line_split[y])
	{
		if (ft_strchr(line_split[y], ','))
		{
			color_split = ft_split(line_split[y], ',');
			fdf->map.colors[fdf->map.x][y] = ft_hexstrtoi(color_split[1]);
			ft_free_split(color_split);
		}
		z = ft_atoi(line_split[y]);
		fdf->map.points[fdf->map.x][y] = z;
		if (z > fdf->map.z_max)
			fdf->map.z_max = z;
		if (z < fdf->map.z_min)
			fdf->map.z_min = z;
		y++;
	}
	fdf->map.x++;
	ft_free_split(line_split);
}

void	load_map(t_fdf_params *fdf)
{
	char	*line;
	int		fd;

	fd = open(fdf->map.path, O_RDONLY, 0);
	if (fd == -1)
		exit_program(fdf, 1);
	map_malloc(fdf, fd);
	close(fd);
	fd = open(fdf->map.path, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		parse_line(fdf, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}
