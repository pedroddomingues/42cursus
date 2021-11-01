/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:49:24 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/30 23:22:13 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	rotate(t_fdf_params *fdf, int key)
{
	if (key == KEY_Q || key == KEY_V)
		fdf->angles->alpha += 0.05;
	else if (key == KEY_E || key == KEY_B)
		fdf->angles->alpha -= 0.05;
	else if (key == KEY_N)
		fdf->angles->beta += 0.05;
	else if (key == KEY_M)
		fdf->angles->beta -= 0.05;
}

int	key_hook(int key, t_fdf_params *fdf)
{
	if (key == KEY_ESC)
		exit_program(fdf, 0);
	else if (key == KEY_ARROW_LEFT || key == KEY_A)
		fdf->translation_x -= 40;
	else if (key == KEY_ARROW_UP || key == KEY_W)
		fdf->translation_y -= 40;
	else if (key == KEY_ARROW_RIGHT || key == KEY_D)
		fdf->translation_x += 40;
	else if (key == KEY_ARROW_DOWN || key == KEY_S)
		fdf->translation_y += 40;
	else if (key == KEY_Q || key == KEY_V)
		rotate(fdf, key);
	else if (key == KEY_E || key == KEY_B)
		rotate(fdf, key);
	else if (key == KEY_N)
		rotate(fdf, key);
	else if (key == KEY_M)
		rotate(fdf, key);
	else if (key == KEY_PLUS)
		fdf->zoom += 15;
	else if (key == KEY_MINUS)
		fdf->zoom -= 15;
	else
		ft_printf("key: %d\n", key);
	reset_image(fdf);
	return (0);
}
