/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:10:19 by pehenriq          #+#    #+#             */
/*   Updated: 2021/07/05 16:38:25 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line"

static int	appendline(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_strsub(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
	}
	return (1);
}

static int	output(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
		return (0);
	else
		return (appendline(&s[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*res[4096];
	char		*buff;
	char		*tmp;
	int			bytes_read;

	buff = ft_calloc(BUFF_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buff, BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL || bytes_read < 0)
		return (-1);
	while (bytes_read > 0)
	{
		if (res[fd] == NULL)
			res[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(res[fd], buff);
			free(res[fd]);
			res[fd] = tmp;
		}
		if (ft_strchr(res[fd], '\n'))
			break ;
		bytes_read = read(fd, buff, BUFF_SIZE);
	}
	return (output(s, line, bytes_read, fd));
}