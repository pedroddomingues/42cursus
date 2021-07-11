/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pehenriq <pehenriq@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:02:24 by pehenriq          #+#    #+#             */
/*   Updated: 2021/06/22 18:42:28 by pehenriq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int get_next_line(int fd, char **line)
{
    char *buff;

    buff = malloc(BUFFER_SIZE + 1);
    read(fd, buff, BUFFER_SIZE)
}