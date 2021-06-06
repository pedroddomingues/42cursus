/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 12:49:54 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 12:56:35 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strdup(const char *s1)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (size--)
	{
		str[size] = s1[size];
	}
	return (str);
}
