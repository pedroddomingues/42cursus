/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:36:46 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/24 17:10:48 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <error.h>

# include "keys.h"
# include "../../libft/libft.h"

# define	WIN_SIZE_X 1920
# define	WIN_SIZE_Y 1080
# define	PI 3.14159265359

typedef enum e_status {
	LOADING,
	RUNNING,
	ERROR,
	EXITTING
}			t_status;

typedef enum e_color_mode {
	SOLID = 0,
	GRADIENT = 1,
	RAINBOW = 2,
}			t_color_mode;

typedef struct s_angles {
	float	alpha;
	float	beta;
	float	gama;
}				t_angles;

typedef struct s_point {
	float		x;
	float		y;
	int			z;
	int			color;
}				t_point;

typedef struct s_map {
	char	*map_name;
	char	*path;
	int		**points;
	int		**colors;
	int		x_max;
	int		y_max;
	int		z_max;
	int		z_min;
	int		x;
}				t_map;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf_params {
	void			*mlx;
	void			*win;
	t_img			img;
	t_map			map;
	t_angles		*angles;
	float			zoom;
	int				translation_x;
	int				translation_y;
	float			z_multiplier;
	t_status		status;
	t_color_mode	color_mode;
	int				color_one;
	int				color_two;
	float			x_step;
	float			y_step;
	int				instructions;
}				t_fdf_params;

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				get_color(t_fdf_params *fdf, int z);

t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv);

void			load_map(t_fdf_params *fdf);

void			prepare_points(t_fdf_params *fdf, t_point *point);
t_point			new_point(float x, float y, int z, int color);

void			print_fdf(t_fdf_params *fdf);
void			print_instructions(t_fdf_params *fdf);
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);

int				key_hook(int key, t_fdf_params *fdf);

void			exit_program(t_fdf_params *fdf, int code);

#endif
