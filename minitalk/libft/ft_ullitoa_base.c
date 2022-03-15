/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:59:54 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/12 00:46:31 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa_base(unsigned long long int n, char *base)
{
	unsigned long long int	nbr;
	char					*a;
	int						b_len;
	int						size;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	n /= b_len;
	while (n && size++)
		n /= b_len;
	a = (char *)malloc(size + 1);
	if (!a)
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
}
