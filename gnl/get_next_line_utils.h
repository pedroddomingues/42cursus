/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:53:02 by pehenriq          #+#    #+#             */
/*   Updated: 2021/07/05 17:15:00 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 8
# define FD_SIZE 4096

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

void	ft_strdel(char **as);

#endif
