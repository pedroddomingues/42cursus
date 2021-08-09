/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:53:48 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/09 12:53:54 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	len;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		slen;
	int		offset;

	slen = ft_strlen(s);
	dst = (char *)malloc((slen + 1) * sizeof(char));
	if (!dst)
		return (0);
	offset = 0;
	while (offset < slen + 1)
	{
		((unsigned char *)dst)[offset] = ((unsigned char *)s)[offset];
		offset++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			current_char;
	unsigned int	i;

	if (src == NULL)
		return (0);
	if (size > 0)
	{
		i = 0;
		current_char = src[i];
		while (current_char != '\0' && i < (size - 1))
		{
			dst[i] = current_char;
			i++;
			current_char = src[i];
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (calloc(1, sizeof(char)));
	s_len = ft_strlen(s + start);
	if ((s_len) < len)
		len = s_len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_strlcpy(str, (s + start), len + 1);
	return (str);
}
