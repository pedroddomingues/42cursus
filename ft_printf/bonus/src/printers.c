/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:02:59 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/28 18:12:32 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_hex_pre(char x)
{
	ft_putstr_fd("0", 1);
	ft_putchar_fd(x, 1);
	return (2);
}

int	print_c(char *str, int arg, t_printf_arg *flags_and_specifiers)
{
	char	c;

	flags_and_specifiers->signal = 1;
	if (*str == '%')
		c = '%';
	else
		c = arg;
	write(1, &c, 1);
	str++;
	return (1);
}

int	print_s(char *str, char *arg, t_printf_arg *flags_and_specifiers)
{
	int	len;
	flags_and_specifiers->signal = 1;

	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(arg);
	str++;
	ft_putstr_fd(arg, 1);
	return (len);
}

int	print_d(char *str, int arg, t_printf_arg *flags_and_specifiers)
{
	char	*number_str;
	flags_and_specifiers->signal = 1;
	int		len;

	if (*str == 'u')
		number_str = ft_ullitoa_base((unsigned int) arg, DECIMAL);
	else
		number_str = ft_itoa(arg);
	len = ft_strlen(number_str);
	ft_putstr_fd(number_str, 1);
	free(number_str);
	return (len);
}

int	print_x(char *str, unsigned long int arg, t_printf_arg *flags_and_specifiers)
{
	char	*number_str;
	int		width;
	int		len;
	int		diff;

	width = 0;
	if (*str == 'p')
	{
		width += print_hex_pre('x');
		number_str = ft_ullitoa_base(arg, HEXALOWER);
	}
	else if (*str == 'X')
	{
		// if (flags_and_specifiers->hash)
		// 	width += print_hex_pre('X');
		number_str = ft_ullitoa_base((unsigned int) arg, HEXAUPPER);
	}
	else
	{
		number_str = ft_ullitoa_base((unsigned int) arg, HEXALOWER);
	}
	if (flags_and_specifiers->hash && (*str == 'X' || *str == 'x'))
		width += 2;
	len = ft_strlen(number_str);
	diff = flags_and_specifiers->width - len - width;
	if (diff && !flags_and_specifiers->left_zeroes)
		ft_putnchar_fd(diff, ' ', 1);
	if (flags_and_specifiers->hash && *str == 'X')
		print_hex_pre('X');
	else if (flags_and_specifiers->hash && *str == 'x')
		print_hex_pre('x');
	if (diff && flags_and_specifiers->left_zeroes)
		ft_putnchar_fd(diff, '0', 1);
	ft_putstr_fd(number_str, 1);
	width += len;
	free(number_str);
	return (width);
}
