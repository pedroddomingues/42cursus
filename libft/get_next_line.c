/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:37:57 by pehenriq          #+#    #+#             */
/*   Updated: 2022/01/16 12:51:13 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_line(char *buffer)
{
	int	i;

	if (buffer)
	{
		i = 0;
		while (buffer[i] != '\n' && buffer[i])
			i++;
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

static int	get_buffer(int fd, char **static_buffer)
{
	char	*buffer;
	char	*tmp;
	int		ret;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char *));
	if (!buffer)
		return (-1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!*static_buffer)
			*static_buffer = ft_strdup(buffer);
		else
		{
			tmp = *static_buffer;
			*static_buffer = ft_strjoin(tmp, buffer);
			free(tmp);
		}
		if (has_line(*static_buffer) >= 0)
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ret);
}

static void	get_line(char **buffer, char **line)
{
	char	*tmp;
	int		i;

	if (*buffer)
	{
		i = has_line(*buffer);
		if (i >= 0)
		{
			tmp = *buffer;
			*line = ft_substr(tmp, 0, i + 1);
			*buffer = ft_substr(tmp, i + 1, ft_strlen(tmp));
			free(tmp);
			if (ft_strlen(*buffer) == 0)
			{
				free(*buffer);
				*buffer = NULL;
			}
		}
		else
		{
			*line = ft_strdup(*buffer);
			free(*buffer);
			*buffer = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	ret = get_buffer(fd, &buffer[fd]);
	line = NULL;
	if (ret == -1)
	{
		if (buffer[fd])
			free(buffer[fd]);
	}
	else
		get_line(&buffer[fd], &line);
	return (line);
}
