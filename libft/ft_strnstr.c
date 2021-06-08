/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:41:23 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/06 18:42:58 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)big;
	if (big[0] == '\0')
		return (NULL);
	if (little[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == little[j])
		{
			while (str[i + j] == little[j] && i + j < len && little[j] != '\0')
			{
				j++;
			}
			if (little[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
