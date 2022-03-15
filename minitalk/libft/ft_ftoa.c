/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:25:48 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/23 15:46:25 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ftoa(float number)
{
	float	decimals;
	char	*units;
	char	*str;
	int		int_len;

	units = ft_itoa((int)number);
	int_len = ft_strlen(units);
	if (number < 0)
		decimals = (int)(number * -100) % 100;
	else
		decimals = (int)(number * 100) % 100;
	str = malloc(sizeof(char) * (int_len + 4));
	if (!str)
		return (NULL);
	str[int_len + 3] = '\0';
	str[int_len] = '.';
	str[int_len + 2] = (int)decimals % 10 + '0';
	decimals /= 10;
	str[int_len + 1] = (int)decimals % 10 + '0';
	ft_strncpy(str, units, int_len);
	free(units);
	return (str);
}
