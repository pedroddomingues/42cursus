/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 20:41:23 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/02 20:32:04 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strnstr(const char	*big, const char *little, size_t len)
{
	int		i;
	int		j;
	char	*ptr;

	if (little[0] == '\0')
		return (0);
	i = 0;
	while (big[i] != '\0' && i < (int len))
	{
		j = 0;
		if (big[i] == little[j])
		{
			ptr = &big[i];
			while (big[i + j] == little[j] && i + j < (int len))
			{
				j++;
			}
			if (little[j] == '\0')
				return (ptr);
		}
		i++;
	}
	return (0);
}
