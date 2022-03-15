/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:37:45 by pehenriq          #+#    #+#             */
/*   Updated: 2022/03/13 21:35:32 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int	g_continue = 0;
int	g_end = 0;

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
		count --;
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
	{
		printf("\nMessage sent to %d!\n", info->si_pid);
		g_end = 1;
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;
	char				message[512];

	if (argc != 2)
	{
		printf("usage: %s [pid]\n", argv[0]);
		return (1);
	}
	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (42)
	{
		printf("Enter message: ");
		fgets(message, 512, stdin);
		message[strlen(message) - 1] = '\0';
		send_message(atoi(argv[1]), message);
		if (!g_end)
			pause();
		g_end = 0;
	}
}
