/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:11:34 by coder             #+#    #+#             */
/*   Updated: 2022/03/01 20:36:22 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_list	*create_list(char *message, int pid)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->message = ft_strdup(message);
	list->pid = pid;
	list->next = NULL;
	return (list);
}

t_list	*add_list(t_list *list, char *message, int pid)
{
	t_list	*new;

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

t_list	*search_pid(t_list *list, int pid)
{
	while (list)
	{
		if (list->pid == pid)
			return (list);
		list = list->next;
	}
	return (NULL);
}
