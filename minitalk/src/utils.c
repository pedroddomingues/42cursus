/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:07:56 by coder             #+#    #+#             */
/*   Updated: 2022/03/01 20:33:20 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i) != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*str;

	size = ft_strlen(s1) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	while (size--)
	{
		((unsigned char *)str)[size] = ((unsigned char *)s1)[size];
	}
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strappend(char *str, char add)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	ft_strcpy(tmp, str);
	tmp[ft_strlen(str)] = add;
	tmp[ft_strlen(str) + 1] = '\0';
	return (tmp);
}
