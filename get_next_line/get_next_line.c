/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:45:09 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/29 10:30:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	int				i;

	if (read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
		return (NULL);
	}
	if (!buffer[0])
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
	line = seek_line(fd, buffer);
	over_read(buffer);
	return (line);
}
