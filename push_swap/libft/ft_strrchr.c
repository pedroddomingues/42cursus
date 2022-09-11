/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:35:50 by pehenriq          #+#    #+#             */
/*   Updated: 2022/02/13 19:26:26 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s);
	str = (char *)s;
	while (size + 1)
	{
		if (str[size] == (char)c)
			return (&str[size]);
		size--;
	}
	return (0);
}
