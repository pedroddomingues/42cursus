/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:10:04 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/06 21:47:51 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char			*num;
	int				rem;
	int				len;
	size_t			i;
	const char		neg = (n < 0);

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	num = ft_calloc(ft_number_width(n, base) + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (neg)
		n = -n;
	i = 0;
	len = ft_strlen(base);
	while (i < ft_number_width(n, base))
	{
		rem = n % len;
		n = n / len;
		num[i] = base[rem];
		i++;
	}
	if (neg)
		num[i - 1] = '-';
	return (ft_strrev(num));
}
