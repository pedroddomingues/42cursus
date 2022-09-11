/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:40:50 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/06 23:06:00 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_width(int n, char *base)
{
	int	width;

	width = 1;
	while (n > 0)
	{
		n /= ft_strlen(base);
		width++;
	}
	return (width);
}
