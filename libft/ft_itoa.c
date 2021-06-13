/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:18:29 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/13 14:00:09 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_digits(int n)
{
	size_t	digits;

	digits = 0;
	while (n)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				rem;
	size_t			i;
	const char		neg = (n < 0);
	const size_t	digits = get_digits(n);

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	num = ft_calloc(digits + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (neg)
		n = -n;
	i = 0;
	while (i < digits)
	{
		rem = n % 10;
		n = n / 10;
		num[i] = "0123456789"[rem];
		i++;
	}
	if (neg)
		num[i - 1] = '-';
	return (ft_strrev(num));
}
