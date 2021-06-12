/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 23:27:48 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/11 23:28:05 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*start;
	unsigned int	count;

	count = 0;
	start = dest;
	while ((src[count] != '\0') && count < n)
	{
		*start = src[count];
		start++;
		count++;
	}
	while (count < n)
	{
		*start = '\0';
		start++;
		count++;
	}
	return (dest);
}
