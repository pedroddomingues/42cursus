/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:53:26 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/08 00:00:58 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (start >= ft_strlen(s))
		return ((char *)ft_memset(str, 0, 1));
	if (!str)
		return (NULL);
	ft_memset(str + len, 0, 1);
	return (ft_memmove(str, &s[start], len));
}
