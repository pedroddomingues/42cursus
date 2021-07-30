/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:45:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/07/30 21:34:21 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != 0)
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}

int	print_c(char *str, va_list ap)
{
	char	c;

	c = (*str == '%') ? '%' : va_arg(ap, int);
	write(1, &c, 1);
	str++;
	return (1);
}

int	print_s(char *str, va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	str++;
	return (len);
}

int	check_conversion(char *str, va_list ap) {
	int	i;

	i = 0;
	if (*str == 'c' || *str == '%')
		i += print_c(str, ap);
	else if (*str == 's')
		i += print_s(str, ap);
	// else if (*str == 'p')
	// 	i += print_p(str, ap);
	// else if (*str == 'd')
	// 	i += print_d(str, ap);
	// else if (*str == 'u')
	// 	i += print_u(str, ap);
	// else if (*str == 'i')
	// 	i += print_i(str, ap);
	return (i);
}

int	ft_printf(const char *str, ...) {
	int	i;
	va_list ap;

	i = 0;
	va_start(ap, str);
	while (*str) {
		if (*str == '%') {
			i += check_conversion((char *)++str, ap);
		} else {
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}

int	main(void) {
	char	str[] = "testandoooooooooooon";
	char	c;
	int		i;

	c = 'x';
	i = ft_printf("a%clo tudo b%c%cem%c c%%om%c%c%co va%ci\n%s\n", c, c, c, c, c, c, c, c, str);
	printf("%d\n", i);
	// ft_printf(CONVERSIONS);
	return (1);
}
