/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:53:02 by pehenriq          #+#    #+#             */
/*   Updated: 2021/07/05 17:16:22 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) b;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, 0, n);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
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

void	ft_strdel(char **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
