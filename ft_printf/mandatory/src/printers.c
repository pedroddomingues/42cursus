/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:02:59 by pehenriq          #+#    #+#             */
/*   Updated: 2021/09/01 23:38:04 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_c(char *str, int arg)
{
	char	c;

	if (*str == '%')
		c = '%';
	else
		c = arg;
	write(1, &c, 1);
	str++;
	return (1);
}

int	print_s(char *str, char *arg)
{
	int	len;
	char	*s;

	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	s = ft_strdup(arg);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	str++;
	return (len);
}

int	print_d(char *str, int arg)
{
	char	*number_str;
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

int	print_x(char *str, unsigned long int arg)
{
	char	*number_str;
	int		width;

	width = 0;
	if (*str == 'p')
	{
		width += 2;
		ft_putstr_fd("0x", 1);
		number_str = ft_ullitoa_base(arg, HEXALOWER);
	}
	else if (*str == 'X')
		number_str = ft_ullitoa_base((unsigned int) arg, HEXAUPPER);
	else
		number_str = ft_ullitoa_base((unsigned int) arg, HEXALOWER);
	ft_putstr_fd(number_str, 1);
	width += ft_strlen(number_str);
	free(number_str);
	return (width);
}
