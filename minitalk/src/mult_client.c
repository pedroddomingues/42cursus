/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:52:08 by pehenriq          #+#    #+#             */
/*   Updated: 2022/03/04 13:30:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_count = 0;

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;
	
	i++;
	(void)context;
	(void)sig;
	if (info->si_status == 0)
		printf("\nChild %d executed.\n", info->si_pid);
	else
		printf("Child %d exited with status %d.\n", info->si_pid, info->si_status);
	if (i == g_count)
	{
		printf("exited from signal\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;
	int					i;

	i = 0;
	g_count = atoi(argv[1]);
	if (argc != 4)
	{
		printf("usage: %s [number of processes] [pid] [message]\n", argv[0]);
		return (1);
	}
	if (fork() == 0)
	{
		action.sa_sigaction = signal_handler;
		action.sa_flags = SA_SIGINFO;
		action.sa_flags += SA_NODEFER;
		sigemptyset(&action.sa_mask);
		sigaddset(&action.sa_mask, SIGCHLD);
		sigaction(SIGCHLD, &action, NULL);
		while (i < g_count)
		{
			if (fork() == 0)
			{
				printf("(%d) Child %d created.\n\n", i + 1, getpid());
				execl("/home/coder/42/tests/minitalk/client", "/home/coder/42/tests/minitalk/client", argv[2], argv[3], NULL);
			}
			usleep(300000);
			i++;
		}
	}
	wait(NULL);
	return (0);
}
