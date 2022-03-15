/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 15:05:35 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/10 15:35:47 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_wordsnum(const char *s, char c)
{
	int		is_word;
	size_t	words;

	words = 0;
	is_word = 0;
	while (*s)
	{
		if (!is_word && *s != c)
		{
			is_word = 1;
			words++;
		}
		else if (is_word && *s == c)
			is_word = 0;
		s++;
	}
	return (words);
}

size_t	get_wordlen(const char *s, char c)
{
	size_t	offset;

	offset = 0;
	while (s[offset] && s[offset] != c)
		offset++;
	return (offset);
}

char	*worddup(const char *s, size_t len)
{
	char	*str;
	size_t	offset;

	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	offset = 0;
	while (offset < len)
	{
		str[offset] = s[offset];
		offset++;
	}
	str[offset] = '\0';
	return (str);
}

static void	*kill(char **res, size_t stop)
{
	size_t	counter;

	counter = 0;
	while (counter < stop)
		free(res[counter]);
	free(res);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	len;
	size_t	words;
	size_t	counter;

	if (s == NULL)
		return (NULL);
	words = get_wordsnum(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	counter = 0;
	while (counter < words)
	{
		len = get_wordlen(s, c);
		if (len)
		{
			res[counter] = worddup(s, len);
			if (res[counter++] == NULL)
				return (kill(res, counter - 1));
		}
		s += len + 1;
	}
	res[counter] = NULL;
	return (res);
}
