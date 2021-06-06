/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:32:09 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/04 16:33:50 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	i;

	i = 0;
	while (i < (int n))
	{
		if ((unsigned char *)s1[i] != (unsigned char *)s2[i])
			return ((unsigned char *)s1[i] - (unsigned char *)s2[i]);
		i++;
	}
	return (0);
}