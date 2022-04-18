/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:04:14 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:05:15 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

float	ft_pow(float base, int exp)
{
	float	result;

	result = 1;
	if (exp < 0)
		return (0);
	while (exp--)
		result *= base;
	return (result);
}
