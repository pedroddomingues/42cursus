/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:45:46 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/31 22:07:12 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

static int	check_conversion(char *str, va_list ap, t_printf_arg *flags_and_specifiers)
{
	int	i;

	i = 0;
	if (*str == 'c' || *str == '%')
		i += print_c(str, va_arg(ap, int), flags_and_specifiers);
	else if (*str == 's')
		i += print_s(str, va_arg(ap, char *), flags_and_specifiers);
	else if (*str == 'd' || *str == 'i' || *str == 'u')
		i += print_d(str, va_arg(ap, int), flags_and_specifiers);
	else if (*str == 'x' || *str == 'X' || *str == 'p')
		i += print_x(str, va_arg(ap, unsigned long int), flags_and_specifiers);
	// printf("\nc2: %c\n", *str);
	return (i);
}

static void	reset_flags(t_printf_arg *flags_and_specifiers)
{
	flags_and_specifiers->width = 0;
	flags_and_specifiers->left_justify = 0;
	flags_and_specifiers->left_zeroes = 0;
	flags_and_specifiers->precision = 0;
	flags_and_specifiers->hash = 0;
	flags_and_specifiers->left_space = 0;
	flags_and_specifiers->signal = 0;
}

// static void	print_flags(t_printf_arg *flags_and_specifiers)
// {
// 	printf("\nwidth: %d\n", flags_and_specifiers->width);
// 	printf("justify: %d\n", flags_and_specifiers->left_justify);
// 	printf("zeroes: %d\n", flags_and_specifiers->left_zeroes);
// 	printf("precision: %d\n", flags_and_specifiers->precision);
// 	printf("hash: %d\n", flags_and_specifiers->hash);
// 	printf("space: %d\n", flags_and_specifiers->left_space);
// 	printf("signal: %d\n\n\n", flags_and_specifiers->signal);
// }

static int	check_flags(char *str, t_printf_arg *flags_and_specifiers)
{
	int	i;

	i = 0;
	reset_flags(flags_and_specifiers);
	while (ft_strchr(FLAGS, *++str) || ft_isdigit(*str))
	{
		if (*str == '0' && flags_and_specifiers->width == 0)
			flags_and_specifiers->left_zeroes = 1;
		else if (ft_isdigit(*str) && flags_and_specifiers->precision == 0 && flags_and_specifiers->width == 0)
			flags_and_specifiers->width = ft_atoi(str);
		else if (*str == '.')
			flags_and_specifiers->precision = ft_atoi(str + 1);
		else if (*str == '-')
			flags_and_specifiers->left_justify = 1;
		else if (*str == '#')
			flags_and_specifiers->hash = 1;
		else if (*str == ' ')
			flags_and_specifiers->left_space = 1;
		else if (*str == '+')
			flags_and_specifiers->signal = 1;
		i++;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	t_printf_arg	*flags_and_specifiers;
	va_list			ap;
	int				i;

	i = 0;
	flags_and_specifiers = malloc(sizeof(t_printf_arg));
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str += check_flags((char *)str, flags_and_specifiers);
			// print_flags(flags_and_specifiers);
			i += check_conversion((char *)++str, ap, flags_and_specifiers);
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(ap);
	free(flags_and_specifiers);
	return (i);
}

// int	main(void)
// {

// 	// check_flags("hello", flags_and_specifiers);
// 	ft_printf("%1x\n", 0);
// 	printf("%1x\n", 0);
// 	// printf("%d\n", ft_atoi("575565-d % d %#+0s sdghsd\n"));
// 	return (0);
// }
