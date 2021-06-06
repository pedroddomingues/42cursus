/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 23:25:21 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 12:42:18 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
