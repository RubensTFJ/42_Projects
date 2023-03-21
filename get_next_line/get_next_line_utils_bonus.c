/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:00:53 by rteles-f          #+#    #+#             */
/*   Updated: 2022/11/20 18:14:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*seek_line(int fd, char *buffer)
{
	char	*line;
	int		i;

	line = NULL;
	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	while (buffer[0] && buffer[i] != '\n')
	{
		line = bl_strjoin(line, buffer);
		if (!line)
			return (NULL);
		buffer[read(fd, buffer, BUFFER_SIZE)] = 0;
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
	}
	line = bl_strjoin(line, buffer);
	return (line);
}

char	*bl_strjoin(char *line, char *add)
{
	int		i;
	int		length[2];
	char	*joined;

	length[0] = 0;
	while (line && line[length[0]])
		length[0]++;
	length[1] = 0;
	while (add && add[length[1]] && add[length[1]] != '\n')
		length[1]++;
	joined = malloc (sizeof(char) * (length[0] + length[1] + \
		1 + (add[length[1]] == '\n')));
	if (!joined)
		return (NULL);
	i = -1;
	while (line && line[++i])
		joined[i] = line[i];
	i = -1;
	while (add && add[++i] && (i == 0 || add[i - 1] != '\n'))
		joined[length[0] + i] = add[i];
	joined[length[0] + i] = '\0';
	if (line)
		free(line);
	return (joined);
}

void	over_read(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i += (buffer[i] == '\n');
	j = 0;
	while (i < BUFFER_SIZE)
		buffer[j++] = buffer[i++];
	while (j < BUFFER_SIZE)
		buffer[j++] = 0;
}
