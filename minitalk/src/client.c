/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:08:20 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 00:15:56 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static void	send_signal(int pid, int signal)
{
	kill(pid, signal);
}

static void	convert_bin(pid_t	pid, char c)
{
	int	x;
	int	count;

	count = 8;
	while (count >= 0)
	{
		x = c >> count;
		if ((x & 1) == 1)
			send_signal(pid, SIGUSR2);
		else
			send_signal(pid, SIGUSR1);
		usleep(1000);
		count--;
	}
}

static void	send_message(int pid, char *message)
{
	while (*message)
	{
		convert_bin(pid, *message);
		message++;
	}
	convert_bin(pid, *message);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf("usage: %s [pid] [message]\n", argv[0]);
		return (1);
	}
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
