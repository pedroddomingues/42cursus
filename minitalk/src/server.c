/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:08:22 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 00:15:56 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_data	g_data;

static void	add_char(int c)
{
	char	*tmp;

	if (c == '\0' && g_data.message)
		g_data.end = 1;
	else
	{
		if (g_data.message)
		{
			tmp = ft_strappend(g_data.message, c);
			free(g_data.message);
			g_data.message = tmp;
		}
		else
		{
			tmp = malloc(sizeof(char) * 2);
			tmp[0] = c;
			tmp[1] = '\0';
			g_data.message = tmp;
		}
	}
}

static void	convert_bin2char(int bit)
{
	static int	i = 8;
	static char	character = 0;

	character += (bit << i);
	i--;
	if (i < 0)
	{
		add_char(character);
		character = 0;
		i = 8;
	}
}

static void	action_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	convert_bin2char(sig == SIGUSR2);
	if (g_data.end)
	{
		ft_printf("Message from %d: %s\n", info->si_pid,
			g_data.message);
		free(g_data.message);
		g_data.message = NULL;
		g_data.end = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	g_data.end = 0;
	g_data.message = NULL;
	ft_printf("SERVER PID: %d\n\n", getpid());
	sa.sa_sigaction = action_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
}
