/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:35:50 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/02 20:38:17 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strrchr(const char	*s, int	c)
{
	int	size;

	size = ft_strlen(s);
	while (size + 1)
	{
		if (s[size] == (char c))
			return (&s[size]);
		size--;
	}
	return (0);
}
