/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:40:50 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/06 21:43:59 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_number_width(int n, char *base)
{
	size_t	width;

	width = (n <= 0);
	while (n)
	{
		n /= ft_strlen(base);
		width++;
	}
	return (width);
}
