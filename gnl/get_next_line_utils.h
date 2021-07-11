/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:53:02 by pehenriq          #+#    #+#             */
/*   Updated: 2021/07/05 18:05:06 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE__UTILS_H
# define GET_NEXT_LINE__UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

void	ft_strdel(char **as);

char	*ft_strchr(const char *s, int c);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
