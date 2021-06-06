/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:42:09 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 12:41:48 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != (unsigned char) c)
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == (unsigned char) c)
	{
		dst[i] = src[i];
		return (&dst[i + 1]);
	}
	return (NULL);
}
