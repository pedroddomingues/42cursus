/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:37:17 by pehenriq          #+#    #+#             */
/*   Updated: 2021/10/09 19:27:45 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	has_duplicates(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	has_signals(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_putnbr_new(int nbr, char *base, int size, int fd)
{
	char			c;
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size)
		ft_putnbr_new(n / size, base, size, fd);
	c = base[n % size];
	write(fd, &c, 1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (baselen < 2 || has_duplicates(base, baselen) || has_signals(base))
		return ;
	ft_putnbr_new(nbr, base, baselen, fd);
}
