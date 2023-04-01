/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:36:02 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 22:07:45 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqheader.h"

typedef struct square_structure	t_square;
typedef struct table_structure	t_table;

int	get_line_size(int fd)
{
	int		line_size;
	char	current_char;

	current_char = ' ';
	while (current_char != '\n')
	{
		read(fd, &current_char, 1);
	}
	read(fd, &current_char, 1);
	line_size = 0;
	while (current_char != '\n')
	{
		read(fd, &current_char, 1);
		line_size++;
	}
	return (line_size);
}

int	get_height(int fd)
{
	int		i;
	char	current_char;
	char	end;

	i = 0;
	end = 1;
	current_char = ' ';
	while (end != 0)
	{
		end = read(fd, &current_char, 1);
		if (current_char == '\n')
		{
			i++;
		}
	}
	return (i - 2);
}

t_table	*allocate_table(int *dimensions)
{
	t_table		*new_table;
	int			i;

	new_table = malloc(sizeof(t_table));
	if (!new_table)
		return (new_table);
	new_table->table = malloc(sizeof(char *) * dimensions[0]);
	if (!new_table)
		return (new_table);
	i = 0;
	while (i < dimensions[0])
	{
		new_table->table[i] = malloc(sizeof(char) * dimensions[1]);
		if (!new_table)
			return (new_table);
		i++;
	}
	new_table->dimensions = malloc(sizeof(int) * 2);
	if (!new_table)
		return (new_table);
	new_table->dimensions[0] = dimensions[0];
	new_table->dimensions[1] = dimensions[1];
	return (new_table);
}

void	fill_table(t_table *table_ready, int fd)
{
	int		i;
	int		current_char;

	current_char = ' ';
	i = 0;
	while (current_char != '\n')
	{
		read(fd, &current_char, 1);
		i++;
	}
	i = 0;
	while (i < table_ready->dimensions[0])
	{
		read(fd, table_ready->table[i], table_ready->dimensions[1]);
		read(fd, &current_char, 1);
		i++;
	}
}

t_table	*read_file(char *file)
{
	int		file_descriptor;
	int		dimensions[2];
	t_table	*table_ready;

	file_descriptor = open(file, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	else
	{
		dimensions[0] = get_height(file_descriptor);
		close(file_descriptor);
		file_descriptor = open(file, O_RDONLY);
		dimensions[1] = get_line_size(file_descriptor);
	}
	close(file_descriptor);
	file_descriptor = open(file, O_RDONLY);
	table_ready = allocate_table(dimensions);
	if (!table_ready)
		return (table_ready);
	fill_table(table_ready, file_descriptor);
	close(file_descriptor);
	return (table_ready);
}
