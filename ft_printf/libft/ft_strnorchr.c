/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnorchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:35:50 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/11 23:26:02 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnorchr(const char	*s, int	c)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s);
	str = (char *)s;
	while (size + 1)
	{
		if (str[size] != (char)c)
			return (&str[size]);
		size--;
	}
	return (0);
}
