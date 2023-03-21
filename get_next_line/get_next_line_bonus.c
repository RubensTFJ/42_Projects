/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:45:09 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/18 18:11:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char		buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char			*line;
	int				i;

	if (read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		i = 0;
		if (fd > -1 && fd < FOPEN_MAX)
			while (i < BUFFER_SIZE)
				buffer[fd][i++] = 0;
		return (NULL);
	}
	if (!buffer[fd][0])
		buffer[fd][read(fd, buffer[fd], BUFFER_SIZE)] = 0;
	line = seek_line(fd, buffer[fd]);
	over_read(buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		go;

// 	fd = open("text", O_RDONLY);
// 	go = 1;
// 	while (go < 10)
// 	{
// 		line = NULL;
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		if (line)
// 			free(line);
// 		go++;
// 	}
// }