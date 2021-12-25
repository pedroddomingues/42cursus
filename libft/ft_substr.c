/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:53:26 by pehenriq          #+#    #+#             */
/*   Updated: 2021/11/02 10:52:05 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = start;
	tmp = malloc(sizeof(char));
	if (!tmp)
		return (NULL);
	*tmp = '\0';
	if (i >= ft_strlen(s))
		return (tmp);
	free(tmp);
	j = 0;
	while (s[i++] != '\0' && j < len)
		j++;
	tmp = malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	while (s[start] != '\0' && j < len)
		tmp[j++] = s[start++];
	tmp[j] = '\0';
	return (tmp);
}
