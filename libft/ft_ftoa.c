/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:25:48 by pehenriq          #+#    #+#             */
/*   Updated: 2022/04/17 23:28:12 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_decimals(char *str, int int_len, int precision, float decimals)
{
	str[int_len + precision + 1] = '\0';
	str[int_len] = '.';
	while (precision)
	{
		str[int_len + precision] = (int)decimals % 10 + '0';
		decimals /= 10;
		precision--;
	}
}

char	*ft_ftoa(float number, int precision)
{
	float	decimals;
	char	*units;
	char	*str;
	int		int_len;
	int		precision_len;

	units = ft_itoa((int)number);
	int_len = ft_strlen(units);
	precision_len = ft_pow(10, precision);
	if (number < 0)
		decimals = (int)(number * -precision_len) % precision_len;
	else
		decimals = (int)(number * precision_len) % precision_len;
	str = malloc(sizeof(char) * (int_len + precision + 2));
	if (!str)
		return (NULL);
	put_decimals(str, int_len, precision, decimals);
	ft_strncpy(str, units, int_len);
	free(units);
	return (str);
}
