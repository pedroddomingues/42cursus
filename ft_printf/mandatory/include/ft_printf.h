/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:30:40 by pehenriq          #+#    #+#             */
/*   Updated: 2021/09/04 16:35:34 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS		"cspdiuxX%"

# define HEXALOWER		"0123456789abcdef"
# define HEXAUPPER		"0123456789ABCDEF"
# define DECIMAL		"0123456789"

int			ft_printf(const char *str, ...);

int			print_c(char *str, int arg);
int			print_percent(char *str);
int			print_s(char *str, char *arg);
int			print_d(char *str, int arg);
int			print_x(char *str, unsigned long int arg);

#endif
