/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:37:57 by pehenriq          #+#    #+#             */
/*   Updated: 2021/11/02 09:30:43 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_line_break(char **buff, size_t *nlchar_position)
{
	int	i;

	i = 0;
	if (!*buff)
		return (0);
	while ((*buff)[i] != '\0')
	{
		if ((*buff)[i] == '\n')
		{
			*nlchar_position = i;
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*cut_line(char **buff, size_t *nlchar_position)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 0;
	line = NULL;
	if (!*buff)
		return (NULL);
	tmp = ft_strdup(*buff);
	if (search_line_break(&*buff, &*nlchar_position))
	{
		line = ft_substr(*buff, 0, *nlchar_position);
		free(*buff);
		*buff = ft_substr(tmp, *nlchar_position + 1, ft_strlen(tmp));
	}
	else
	{
		i = ft_strlen(tmp);
		if (i > 0)
			line = ft_substr(tmp, 0, i);
		free(*buff);
		*buff = NULL;
	}
	free(tmp);
	return (line);
}

static void	set_buff(char **buff, char **tmp, char **result)
{
	if (!*buff)
		*buff = ft_strdup(*result);
	else
	{
		*tmp = ft_strdup(*buff);
		free(*buff);
		*buff = ft_strjoin(*tmp, *result);
		free(*tmp);
	}
}

char	*get_next_line(int fd)
{
	size_t		nlchar_position;
	size_t		bytes_read;
	static char	*buff[256];
	char		*result;
	char		*tmp;

	if (fd < 0 || read(fd, NULL, 0) != 0 || BUFFER_SIZE < 0)
		return (NULL);
	result = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, result, BUFFER_SIZE);
	nlchar_position = 0;
	while (bytes_read > 0)
	{
		(result)[bytes_read] = '\0';
		set_buff(&buff[fd], &tmp, &result);
		if (search_line_break(&buff[fd], &nlchar_position))
			break ;
		bytes_read = read(fd, result, BUFFER_SIZE);
	}
	free(result);
	return (cut_line(&buff[fd], &nlchar_position));
}
