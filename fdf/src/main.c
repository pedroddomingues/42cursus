/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:21:18 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/31 13:23:33 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	*parse_line(char *line, int line_width)
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
	return (net_line);
}

int	get_linesnum(int fd)
{
	int	i;

	i = 0;
	if (!get_next_line(fd))
		return (0);
	while (get_next_line(fd))
		i++;
	return (i);
}

void	kill(t_fdf_params *fdf)
{
	int	i;

	i = 1;
	while (i < fdf->map.height)
	{
		free(fdf->map.map[i]);
		i++;
	}
	free(fdf->map.map_name);
	free(fdf->map.path);
	free(fdf->map.map);
}

char	*get_path(t_fdf_params *fdf)
{
	int	name_size;

	name_size = ft_strlen(fdf->map.map_name);
	fdf->map.path = malloc(sizeof(char) * (10 + name_size));
	ft_strcpy(fdf->map.path, "maps/");
	ft_strlcat(fdf->map.path, fdf->map.map_name, name_size + 6);
	ft_strlcat(fdf->map.path, ".fdf", ft_strlen(fdf->map.path) + 5);
	return (fdf->map.path);
}

void	init_map(t_fdf_params *fdf, int fd, char *line, int *map_line)
{
	int	i;
	int	j;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		map_line = parse_line(line, fdf->map.width);
		fdf->map.map[i] = malloc(sizeof(int) * fdf->map.width);
		while (j < fdf->map.width)
		{
			fdf->map.map[i][j] = map_line[j];
			j++;
		}
		free(map_line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(map_line);
}

void	load_map(t_fdf_params *fdf)
{
	char	*line;
	int		*map_line;
	int		fd;

	fd = open(get_path(fdf), O_RDONLY, 0);
	if (fd == -1)
		exit_program(fdf, 1);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		exit_program(fdf, 2);
	}
	fdf->map.width = get_wordsnum(line, ' ');
	// free(line);
	fdf->map.height = get_linesnum(fd);
	close(fd);
	fdf->map.map = malloc(sizeof(int) * fdf->map.height * fdf->map.width);
	fd = open(fdf->map.path, O_RDONLY, 0);
	init_map(fdf, fd, line, map_line);
	close(fd);
}

void	init(t_fdf_params *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_SIZE_X, WIN_SIZE_Y, "fdf - pehenriq");
	fdf->angles = malloc(sizeof(t_angles));
	fdf->angles->alpha = 0.8;
	fdf->angles->beta = 0.8;
	fdf->angles->gama = 0.8;
	fdf->zoom = 100;
	fdf->translation_x = 200;
	fdf->translation_y = 200;
	load_map(fdf);
}

int	main(int argc, char **argv)
{
	t_fdf_params	*fdf;

	fdf = check_initial_errors(fdf, argc, argv);
	init(fdf);
	draw_fdf(fdf);
	mlx_key_hook(fdf->win, &key_hook, fdf);
	mlx_loop(fdf->mlx);
}
