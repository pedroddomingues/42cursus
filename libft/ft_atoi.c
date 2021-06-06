/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:26:48 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 12:41:24 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	return (result);
}
