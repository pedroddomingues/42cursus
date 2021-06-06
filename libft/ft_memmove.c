/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:32:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 12:42:08 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (n--)
		{
			*(unsigned char *)(dst + n) = *(unsigned char *)(src + n);
		}
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
