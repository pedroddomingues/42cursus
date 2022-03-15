/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 00:02:59 by pehenriq          #+#    #+#             */
/*   Updated: 2022/03/13 21:32:17 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_c(char *str, int arg)
{
	write(1, &arg, 1);
	str++;
	return (1);
}

int	print_percent(char *str)
{
	write(1, "%", 1);
	str++;
	return (1);
}

int	print_s(char *str, char *arg)
{
	int	len;

	if (arg == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(arg);
	ft_putstr_fd(arg, 1);
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
