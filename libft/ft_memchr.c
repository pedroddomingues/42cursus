/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:34:31 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/04 16:58:16 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int) n && (unsigned char *)s[i] != (unsigned char) c)
		i++;
	if (i == (int) n)
		return (0);
	return ((unsigned char *)&s[i]);
}