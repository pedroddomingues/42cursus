/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 20:39:43 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/02 20:44:10 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strchr(const char *s, int c)
{
	int	i;
	int	size;

	size = ft_strlen(s);
	i = 0;
	while (i <= size + 1)
	{
		if (s[i] == (char c))
			return (&s[i]);
		i++;
	}
	return (0);
}
