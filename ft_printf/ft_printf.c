/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:45:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/06 23:09:17 by pehenriq         ###   ########.fr       */
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
	str++;
	if (s)
		ft_putstr_fd(s, 1);
	else
	{
		ft_putstr_fd("(null)", 1);
		len = 6;
	}
	return (len);
}

static int	print_d(va_list ap)
{
	int		number;
	int		len;
	char	*number_str;

	number = va_arg(ap, int);
	ft_putnbr_fd(number, 1);
	number_str = ft_itoa(number);
	len = ft_strlen(number_str);
	free(number_str);
	return (len);
}

static int	print_u(va_list ap)
{
	unsigned int	number;

	number = va_arg(ap, unsigned int);
	ft_putnbr_fd(number, 1);
	return (ft_strlen(ft_itoa(number)));
}

static int	print_x(char *str, va_list ap)
{
	unsigned int	number;
	char			*number_str;
	int				width;

	number = va_arg(ap, int);
	// write(1, "0x", 2);
	// i = 2;
	if (*str == 'X')
		number_str = ft_itoa_base(number, HEXAUPPER);
	else
		number_str = ft_itoa_base(number, HEXALOWER);
	ft_putstr_fd(number_str, 1);
	width = ft_strlen(number_str);
	free(number_str);
	return (width);
}

static int	check_conversion(char *str, va_list ap)
{
	int	i;

	i = 0;
	if (*str == 'c' || *str == '%')
		i += print_c(str, ap);
	else if (*str == 's')
		i += print_s(str, ap);
	else if (*str == 'd' || *str == 'i')
		i += print_d(ap);
	else if (*str == 'u')
		i += print_u(ap);
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

// 	// c = 'x';
// 	a = 66789;
// 	// s = &c;
// 	// i = ft_printf("a%clo tudo b%c%cem%c c%%om%c%c%co va%ci\n%s\n%u\n%x\n%s\n",
// 	// 		c, c, c, c, c, c, c, c, str, a, a, s);
// 	// printf("\n\n%d\n\n", i);
// 	// i = printf("a%clo tudo b%c%cem%c c%%om%c%c%co va%ci\n%s\n%u\n%x\n%s\n",
// 	// 		c, c, c, c, c, c, c, c, str, a, a, s);
// 	// printf("\n\n%d\n\n", i);
// 	// printf("%s", s);
// 	ft_printf("%x", a);
// 	return (1);
// }
