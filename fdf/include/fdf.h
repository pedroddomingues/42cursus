/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:36:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/30 22:59:13 by pehenriq         ###   ########.fr       */
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

# define	WIN_SIZE_X 1080
# define	WIN_SIZE_Y 1920
# define	PI 3.14159265359

typedef struct s_angles {
	float	alpha;
	float	beta;
	float	gama;
}				t_angles;

typedef struct s_map {
	char	*map_name;
	char	*path;
	int		**map;
	int		width;
	int		height;
}				t_map;

typedef struct s_img {
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_fdf_params {
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_angles	*angles;
	float		zoom;
	int			translation_x;
	int			translation_y;
}				t_fdf_params;

typedef struct s_point {
	float	x;
	float	y;
	float	z;
}				t_point;

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				rainbow(void);

t_point			set_point(float x, float y, float z);

void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_line(t_fdf_params *fdf, float x, float y, float x1, float y1);

void			print_lines(t_fdf_params *fdf);
t_fdf_params	*check_initial_errors(t_fdf_params *fdf, int argc, char **argv);

int				key_hook(int key, t_fdf_params *fdf);

void			draw_fdf(t_fdf_params *fdf);
void			reset_image(t_fdf_params *fdf);
float			to_rad(int degree);

void			matrix_bzero(float matrix[4][4]);
void			get_id_matrix(float matrix[4][4]);
void			matrix_mult(float m1[4][4], float m2[4][4], float dst[4][4]);
void			matrix_translate(float matrix[4][4], float x, float y, float z);
void			matrix_scale(float matrix[4][4], float x, float y, float z);
t_point			project_point(t_point point);

void	exit_program(t_fdf_params *fdf, int code);

#endif
