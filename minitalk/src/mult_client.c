/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 21:52:08 by pehenriq          #+#    #+#             */
/*   Updated: 2022/03/13 21:34:51 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

int		g_count = 0;

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 0;

	i++;
	(void)context;
	(void)sig;
	if (info->si_status == 0)
		printf("\nChild %d executed in %d seconds.\n",
			info->si_pid, (int) info->si_stime);
	else
		printf("Child %d exited with status %d.\n",
			info->si_pid, info->si_status);
	if (i == g_count)
	{
		printf("exited from signal\n");
		exit(0);
	}
}

static void	configure_action(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sa->sa_flags = SA_SIGINFO;
	sa->sa_flags += SA_NODEFER;
	sigemptyset(&sa->sa_mask);
	sigaddset(&sa->sa_mask, SIGCHLD);
	sigaction(SIGCHLD, sa, NULL);
}

void	usage(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("usage: %s [number of processes] [pid] [message]\n", argv[0]);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	struct sigaction	action;
	int					i;

	i = 0;
	g_count = atoi(argv[1]);
	usage(argc, argv);
	if (fork() == 0)
	{
		configure_action(&action);
		while (i < g_count)
		{
			if (fork() == 0)
			{
				printf("(%d) Child %d created.\n\n", i + 1, getpid());
				execl("/home/coder/42/tests/minitalk/client",
					"/home/coder/42/tests/minitalk/client",
					argv[2], argv[3], NULL);
			}
			sleep(1);
			i++;
		}
	}
	wait(NULL);
	return (0);
}
