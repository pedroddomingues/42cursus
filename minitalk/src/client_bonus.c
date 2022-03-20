/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:08:20 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 00:15:59 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	g_continue = 0;

static void	send_signal(int pid, int signal)
{
	kill(pid, signal);
}

static void	convert_bin(pid_t	pid, char c)
{
	int	x;
	int	count;

	count = 10;
	while (count >= 0)
	{
		x = c >> count;
		if ((x & 1) == 1)
			send_signal(pid, SIGUSR2);
		else
			send_signal(pid, SIGUSR1);
		count--;
		while (!g_continue)
			pause();
		g_continue = 0;
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

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR1)
		g_continue = 1;
	else if (sig == SIGUSR2)
		ft_printf("Message sent to %d very quickly!\n", info->si_pid);
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;

	if (argc != 3)
	{
		ft_printf("usage: %s [pid] [message]\n", argv[0]);
		return (1);
	}
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
