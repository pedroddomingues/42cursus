/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:30:40 by pehenriq          #+#    #+#             */
/*   Updated: 2021/08/28 00:53:25 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS		"cspdiuxX%"
# define FLAGS			"-0.# +"

# define HEXALOWER		"0123456789abcdef"
# define HEXAUPPER		"0123456789ABCDEF"
# define DECIMAL		"0123456789"

typedef struct s_printf_arg
{
	int		width;
	int		left_justify;
	int		left_zeroes;
	int		precision;
	int		hash;
	int		left_space;
	int		signal;
}	t_printf_arg;

int			ft_printf(const char *str, ...);

int			print_c(char *str, int arg, t_printf_arg *flags_and_specifiers);
int			print_s(char *str, char *arg, t_printf_arg *flags_and_specifiers);
int			print_d(char *str, int arg, t_printf_arg *flags_and_specifiers);
int			print_x(char *str, unsigned long int arg,
				t_printf_arg *flags_and_specifiers);

#endif
