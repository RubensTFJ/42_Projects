/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorhandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:25:35 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 22:55:49 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqheader.h"

typedef struct square_structure	t_square;
typedef struct table_structure	t_table;
int	number_check(char *file);
int	symbols_check(char *file);
int	map_check(char *file, char *symbols);
int	open_check(char *file);

int	number_check(char *file)
{
	int		counter;
	char	number;
	char	current_char;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, &current_char, 1);
	counter = 0;
	while (current_char > 47 && current_char < 58)
	{
		number = current_char;
		counter++;
		read(fd, &current_char, 1);
	}
	if (counter == 0 || (counter == 1 && number == '0'))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	symbols_check(char *file)
{
	char	symbols[3];

	get_symbols(file, symbols);
	if (symbols[0] == symbols[1] || symbols[0] == symbols[2]
		|| symbols[1] == symbols[2])
	{
		return (0);
	}
	return (1);
}

// int	symbols_check(char *file)
// {
// 	int		counter;
// 	char	symbols[3];
// 	char	current_char;
// 	int		fd;

// 	fd = open_check(file);
// 	counter = 0;
// 	read(fd, &current_char, 1);
// 	while (current_char > 47 && current_char < 58)
// 		read(fd, &current_char, 1);
// 	while (current_char > 32 && current_char < 127)
// 	{
// 		if (counter < 3)
// 			symbols[counter] = current_char;
// 		counter++;
// 		read(fd, &current_char, 1);
// 	}
// 	if (symbols[0] == symbols[1] || symbols[0] == symbols[2]
// 		|| symbols[1] == symbols[2] || counter != 3)
// 	{
// 		close(fd);
// 		return (0);
// 	}
// 	close(fd);
// 	return (1);
// }

int	open_check(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	return (fd);
}

int	map_check(char *file, char *symbols)
{
	char	current_char;
	int		lines[2];
	int		result;
	int		fd;

	lines[0] = 0;
	lines[1] = 0;
	fd = open_check(file);
	current_char = '0';
	while (current_char != '\n')
		read(fd, &current_char, 1);
	read(fd, &current_char, 1);
	result = check_lines_symbles(fd, current_char, symbols, lines);
	if (result == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_lines_symbles(int fd, char rchar, char *symbols, int *lines)
{
	while (rchar != '\n')
	{
		if (rchar != symbols[0] && rchar != symbols[1])
			return (0);
		read(fd, &rchar, 1);
		lines[0]++;
	}
	if (lines[0] == 0)
		return (0);
	read(fd, &rchar, 1);
	while (read(fd, &rchar, 1))
	{
		lines[1]++;
		if (rchar != symbols[0] && rchar != symbols[1] && rchar != '\n')
			return (0);
		if (rchar == '\n')
		{
			if (read(fd, &rchar, 1) != 1)
				return (1);
			if (lines[0] != lines[1])
				return (0);
			lines[1] = 0;
		}
	}
	return (1);
}
