/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:02:24 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/30 00:35:04 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../libft/libft.h"
#define BUFFER_SIZE 32

// static int	bytes_real_read(int fd, char **line, char *buff, char **rest)
// {
// 	char	*nlchar;
// 	int		buff_len;

// 	buff_len = (int)ft_strlen(buff);
// 	nlchar = ft_strchr(buff, '\n');
// 	if (nlchar)
// 	{
// 		*line = ft_substr(buff, 0, (int)(nlchar - buff));
// 		ft_strncpy(rest[fd], nlchar + 1, buff_len - (int)(nlchar - buff));
// 		printf("rest: %s\n", rest[fd]);
// 		printf("rest_size: %d\n", buff_len - (int)(nlchar - buff));
// 		return (buff_len - (int)(nlchar - buff));
// 	}
// 	return (5);
// }

// static int	eof(void)
// {
// 	return (0);
// }
static int	separate_string_by_char(char *src, char c, char *dst1, char *dst2)
{
	char	*tmp;
	char	*tmp1;
	char	*tmp2;
	size_t	src_size;
	size_t	tmp1_size;

	tmp = ft_strchr(src, c);
	if (!tmp)
		return (-1);
	tmp1_size = (size_t)(tmp - src);
	tmp1 = ft_substr(src, 0, tmp1_size);
	src_size = ft_strlen(src);
	tmp2 = ft_substr(src, tmp1_size + 1, src_size - tmp1_size);
	ft_strcpy(dst1, tmp1);
	ft_strcpy(dst2, tmp2);
	free(tmp1);
	free(tmp2);
	return (42);
}

// int	get_next_line(int fd, char **line)
// {
// 	static char	*rest[FOPEN_MAX];
// 	char		*buff;
// 	static char	*test;
// 	int			bytes_read;

// 	if (rest[fd])
// 	buff = malloc(BUFFER_SIZE + 1);
// 	bytes_read = read(fd, buff, BUFFER_SIZE);
// 	if (!buff || !line || fd < 0 || BUFFER_SIZE <= 0 || bytes_read < 0)
// 		return (-1);
// }

int main(int ac, char **av)
{
	// char	*line;
	// int		fd1;

	// fd1 = open(av[1], O_RDONLY);
	// get_next_line(fd1, &line);
	// printf("line1: %s\n", line);
	// get_next_line(fd1, &line);
	// printf("line2: %s\n", line);
	// get_next_line(fd1, &line);
	// printf("line3: %s\n", line);

	// char		src[] = "testando12345";
	// static char	*dst1;
	// static char	*dst2;
	// char		c;

	// c = 'a';
	// dst1 = malloc(45);
	// dst2 = malloc(45);
	// separate_string_by_char(src, c, dst1, dst2);
	// printf("src: %s\n", src);
	// printf("dst1: %s\n", dst1);
	// printf("dst2: %s\n", dst2);
	return (0);
}
