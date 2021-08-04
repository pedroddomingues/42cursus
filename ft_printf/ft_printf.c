/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:45:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/03 19:37:07 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_c(char *str, va_list ap)
{
	char	c;

	if (*str == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	write(1, &c, 1);
	str++;
	return (1);
}

static int	print_s(char *str, va_list ap)
{
	char	*s;
	int		len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	if (s)
		ft_putstr_fd(va_arg(ap, char *), 1);
	// {
	// 	write(1, "(null)", 6);
	// 	len = 6;
	// }
	// else
	str++;
	return (len);
}

static int	print_d(va_list ap)
{
	int		number;

	number = va_arg(ap, int);
	ft_putnbr_fd(number, 1);
	return (ft_strlen(ft_itoa(number)));
}

static int	print_x(char *str, va_list ap)
{
	int				i;
	unsigned int	number;

	number = va_arg(ap, unsigned int);
	i = 5;
	if (*str == 'X')
		ft_putnbr_base_fd(number, HEXAUPPER, 1);
	else
		ft_putnbr_base_fd(number, HEXALOWER, 1);
	return (i);
}

static int	check_conversion(char *str, va_list ap)
{
	int	i;

	i = 0;
	if (*str == 'c' || *str == '%')
		i += print_c(str, ap);
	else if (*str == 's')
		i += print_s(str, ap);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		i += print_d(ap);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		i += print_x(str, ap);
	// else if (*str == 'p')
	// 	i += print_p(str, ap);
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

// int		main(void)
// {
// 	char			str[] = "testandoooooooooooon";
// 	char			c;
// 	int				i;
// 	unsigned int	a;
// 	char			*s = NULL;

// 	c = 'x';
// 	a = 66789;
// 	s = &c;
// 	i = ft_printf("a%clo tudo b%c%cem%c c%%om%c%c%co va%ci\n%s\n%u\n%x\n%s\n",
// 			c, c, c, c, c, c, c, c, str, a, a, s);
// 	printf("\n\n%d\n\n", i);
// 	i = printf("a%clo tudo b%c%cem%c c%%om%c%c%co va%ci\n%s\n%u\n%x\n%s\n",
// 			c, c, c, c, c, c, c, c, str, a, a, s);
// 	printf("\n\n%d\n\n", i);
// 	return (1);
// }
