/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:10:04 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/06 23:02:22 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	const char		neg = (n < 0);
	char			*num;
	int				rem;
	int				base_len;
	int				i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	num = ft_calloc(ft_number_width(n, base) + 1, sizeof(char));
	if (!num)
		return (NULL);
	if (neg)
		n = -n;
	i = 0;
	base_len = ft_strlen(base);
	while (i < ft_number_width(n, base))
	{
		rem = n % base_len;
		n = n / base_len;
		num[i] = base[rem];
		i++;
	}
	if (neg)
		num[i - 1] = '-';
	return (ft_strrev(num));
}
