/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:47:26 by pehenriq          #+#    #+#             */
/*   Updated: 2021/11/07 14:49:21 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	*parse_line(char *line, int line_width)
{
	int		*net_line;
	char	**tmp;

	tmp = ft_split(line, ' ');
	net_line = malloc(sizeof(int) * line_width);
	line_width--;
	while (line_width >= 0)
	{
		net_line[line_width] = ft_atoi(tmp[line_width]);
		line_width--;
	}
	free_split(tmp);
	return (net_line);
}

static void	populate_map(t_fdf_params *fdf, int fd)
{
	char	*line;
	int		*map_line;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		map_line = parse_line(line, fdf->map.width);
		fdf->map.data[i] = malloc(sizeof(int) * fdf->map.width);
		while (j < fdf->map.width)
		{
			fdf->map.data[i][j] = map_line[j];
			j++;
		}
		free(map_line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

static int	get_linesnum(int fd, char *line)
{
	int	i;

	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (i);
}

void	load_map(t_fdf_params *fdf)
{
	char	*line;
	int		fd;

	fd = open(fdf->map.path, O_RDONLY, 0);
	if (fd == -1)
		error(fdf, 2);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		exit_program(fdf, 3);
	}
	fdf->map.width = get_wordsnum(line, ' ');
	fdf->map.height = get_linesnum(fd, line);
	close(fd);
	fdf->map.data = malloc(sizeof(int *) * fdf->map.height);
	fd = open(fdf->map.path, O_RDONLY, 0);
	populate_map(fdf, fd);
}
