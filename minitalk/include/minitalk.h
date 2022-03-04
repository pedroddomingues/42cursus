/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:07:54 by coder             #+#    #+#             */
/*   Updated: 2022/03/03 19:10:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_list
{
	char			*message;
	int				pid;
	struct s_list	*next;
}		t_list;

typedef struct s_data {
	t_list	*messages;
	int		end;
}		t_data;

t_list	*create_list(char *message, int pid);
t_list	*add_list(t_list *list, char *message, int pid);
t_list	*search_pid(t_list *list, int pid);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strappend(char *str, char add);
char	*ft_strcpy(char *dst, const char *src);

#endif