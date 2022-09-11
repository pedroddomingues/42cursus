/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:45:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/05 23:23:28 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_conversion(char *str, va_list ap)
{
	int	i;

	i = 0;
	if (*str == 'c')
		i += print_c(str, va_arg(ap, int));
	else if (*str == '%')
		i += print_percent(str);
	else if (*str == 's')
		i += print_s(str, va_arg(ap, char *));
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		i += print_d(str, va_arg(ap, int));
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		i += print_x(str, va_arg(ap, unsigned long int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			i += check_conversion((char *)++str, ap);
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}
