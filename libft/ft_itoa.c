/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:18:29 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/13 15:20:11 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_width(int n)
{
	size_t	width;

	width = (n <= 0);
	while (n)
	{
		n /= 10;
		width++;
	}
	return (width);
}

static	char	*strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	tmp;

	if (!str || !*str)
		return (str);
	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				rem;
	size_t			i;
	const char		neg = (n < 0);
	const size_t	width = get_width(n);

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	num = ft_calloc(width + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (neg)
		n = -n;
	i = 0;
	while (i < width)
	{
		rem = n % 10;
		n = n / 10;
		num[i] = "0123456789"[rem];
		i++;
	}
	if (neg)
		num[i - 1] = '-';
	return (strrev(num));
}
