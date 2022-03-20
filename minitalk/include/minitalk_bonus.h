/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:07:54 by coder             #+#    #+#             */
/*   Updated: 2022/03/21 00:01:36 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_minitalk_list
{
	char					*message;
	int						pid;
	int						end;
	struct s_minitalk_list	*next;
}		t_minitalk_list;

typedef struct s_data {
	t_minitalk_list	*messages;
}		t_data;

t_minitalk_list	*create_list(char *message, int pid);
t_minitalk_list	*add_list(t_minitalk_list *list, char *message, int pid);
t_minitalk_list	*search_pid(t_minitalk_list *list, int pid);

#endif
