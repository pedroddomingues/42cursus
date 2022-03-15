/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:14 by coder             #+#    #+#             */
/*   Updated: 2022/03/14 16:35:53 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strappend(char *str, char add)
{
	char	*tmp;

	tmp = malloc(sizeof(char) * (ft_strlen(str) + 2));
	ft_strcpy(tmp, str);
	tmp[ft_strlen(str)] = add;
	tmp[ft_strlen(str) + 1] = '\0';
	return (tmp);
}
