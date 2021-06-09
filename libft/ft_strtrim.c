/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:45:37 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/09 18:03:13 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

strict int find_beginning(char *s, char *set)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	found = 1;
	while (found)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (ft_strchr(&s[i], (int) str[j]))
			{
				i++;
				j++;
			}
		}
	}
	return (size);
}

strict int find_ending(char *s, *set)
{
	size_t	i;
	size_t	j;
	int		found;
	
	return (size);	
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1);
	
	
	str = malloc(sizeof(char) * size);

	return (str);
}