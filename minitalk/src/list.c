/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:11:34 by coder             #+#    #+#             */
/*   Updated: 2022/03/18 19:38:12 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_minitalk_list	*create_list(char *message, int pid)
{
	t_minitalk_list	*list;

	list = malloc(sizeof(t_minitalk_list));
	if (!list)
		return (NULL);
	list->message = ft_strdup(message);
	list->pid = pid;
	list->end = 0;
	list->next = NULL;
	return (list);
}

t_minitalk_list	*add_list(t_minitalk_list *list, char *message, int pid)
{
	t_minitalk_list	*new;

	new = create_list(message, pid);
	if (!new)
		return (NULL);
	if (!list)
		return (new);
	while (list->next)
		list = list->next;
	list->next = new;
	return (new);
}

t_minitalk_list	*search_pid(t_minitalk_list *list, int pid)
{
	while (list)
	{
		if (list->pid == pid)
			return (list);
		list = list->next;
	}
	return (NULL);
}
