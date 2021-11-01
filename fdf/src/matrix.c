/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:56:29 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/17 17:32:03 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	matrix_bzero(float matrix[4][4])
{
	ft_bzero(matrix[0], sizeof(float) * 4);
	ft_bzero(matrix[1], sizeof(float) * 4);
	ft_bzero(matrix[2], sizeof(float) * 4);
	ft_bzero(matrix[3], sizeof(float) * 4);
}

void	get_id_matrix(float matrix[4][4])
{
	matrix_bzero(matrix);
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
	matrix[3][3] = 1;
}

void	matrix_mult(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			dst[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j]
				+ m1[i][2] * m2[2][j] + m1[i][3] * m2[3][j];
	}
}

t_point	project_point(t_point point)
{
	float	iso_matrix[4][4];
	t_point	projected;

	matrix_bzero(iso_matrix);
	iso_matrix[0][0] = 0.707;
	iso_matrix[0][1] = 0.408;
	iso_matrix[1][1] = 0.816;
	iso_matrix[2][0] = 0.707;
	iso_matrix[0][1] = -0.408;
	iso_matrix[3][3] = 1;
	projected.x = point.x * iso_matrix[0][0] + point.y * iso_matrix[1][0] + point.z * iso_matrix[2][0];
	projected.y = point.x * iso_matrix[0][1] + point.y * iso_matrix[1][1] + point.z * iso_matrix[2][1];
	projected.z = 0;
}

void	matrix_translate(float matrix[4][4], float x, float y, float z)
{
	float	trans_matrix[4][4];

	get_id_matrix(trans_matrix);
	trans_matrix[3][0] = x;
	trans_matrix[3][1] = y;
	trans_matrix[3][2] = z;
	matrix_mult(matrix, trans_matrix, matrix);
}

void	matrix_scale(float matrix[4][4], float x, float y, float z)
{
	float	scale_matrix[4][4];

	matrix_bzero(scale_matrix);
	scale_matrix[0][0] = x;
	scale_matrix[1][1] = y;
	scale_matrix[2][2] = z;
	scale_matrix[3][3] = 1;
	matrix_mult(matrix, scale_matrix, matrix);
}
