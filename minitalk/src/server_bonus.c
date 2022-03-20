/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:08:22 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 00:02:00 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

t_data	g_data;

static void	add_char(int c, int pid)
{
	t_minitalk_list	*list;
	char			*tmp;

	list = search_pid(g_data.messages, pid);
	if (c == '\0' && list)
		list->end = 1;
	else
	{
		if (list)
		{
			tmp = ft_strappend(list->message, c);
			free(list->message);
			list->message = tmp;
		}
		else
		{
			list = add_list(g_data.messages, (char *) &c, pid);
			if (!g_data.messages)
				g_data.messages = list;
		}
	}
}

static void	convert_bin2char(int bit, int pid)
{
	static int	i = 10;
	static char	character = 0;

	character += (bit << i);
	i--;
	if (i < 0)
	{
		add_char(character, pid);
		character = 0;
		i = 10;
	}
}

static void	action_handler(int sig, siginfo_t *info, void *ucontext)
{
	t_minitalk_list	*list;

	(void) ucontext;
	convert_bin2char(sig == SIGUSR2, info->si_pid);
	usleep(500);
	kill(info->si_pid, SIGUSR1);
	list = search_pid(g_data.messages, info->si_pid);
	if (list && list->end)
	{
		ft_printf("Message from %d: %s\n", info->si_pid, list->message);
		kill(info->si_pid, SIGUSR2);
		free(list->message);
		free(list);
		g_data.messages = NULL;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_data.messages = NULL;
	ft_printf("SERVER PID: %d\n\n", getpid());
	sa.sa_sigaction = action_handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_flags += SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
}
