/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:39:43 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/13 13:31:21 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		size;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	str = (char *)s;
	while (i <= size)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	return (0);
}
