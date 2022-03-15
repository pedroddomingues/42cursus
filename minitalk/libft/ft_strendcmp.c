/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:02:24 by pehenriq          #+#    #+#             */
/*   Updated: 2022/03/04 13:40:46 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendcmp(char *s1, char *s2)
{
	int	end_size;
	int	s1_size;

	end_size = ft_strlen(s2);
	s1_size = ft_strlen(s1);
	if (end_size > s1_size)
		return (-1);
	return (ft_strncmp(&(s1[s1_size - end_size]), s2, end_size));
}
