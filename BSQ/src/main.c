/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:41:46 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 22:35:58 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqheader.h"

typedef struct square_structure	t_square;
typedef struct table_structure	t_table;

void	get_symbols(char *file, char *result)
{
	int		file_descriptor;
	char	current_char;
	int		length;
	int		i;

	length = line_length(file);
	current_char = ' ';
	file_descriptor = open(file, O_RDONLY);
	if (file_descriptor == -1)
		return ;
	read(file_descriptor, &current_char, 1);
	i = 0;
	while (current_char >= '0' && '9' >= current_char && i < (length - 4))
	{
		read(file_descriptor, &current_char, 1);
		i++;
	}
	result[0] = current_char;
	read(file_descriptor, &current_char, 1);
	result[1] = current_char;
	read(file_descriptor, &current_char, 1);
	result[2] = current_char;
}

int	line_length(char *file)
{
	int		file_descriptor;
	char	current_char;
	int		length;

	file_descriptor = open(file, O_RDONLY);
	if (file_descriptor == -1)
		return (0);
	current_char = '0';
	length = 0;
	while (current_char != '\n')
	{
		read(file_descriptor, &current_char, 1);
		length++;
	}
	close(file_descriptor);
	return (length);
}

void	solve_map(char *file)
{
	t_table		*map_input;
	t_square	*squareinfo;
	char		symbols[3];

	get_symbols(file, symbols);
	map_input = read_file(file);
	if (!map_input)
		return ;
	squareinfo = run_table(map_input->table,
			map_input->dimensions, symbols[0]);
	if (!squareinfo)
		return ;
	putsquare(map_input->table, symbols[2], squareinfo);
	print_table(map_input->table, map_input->dimensions);
	free(squareinfo);
	free(map_input->dimensions);
	free(map_input->table);
	free(map_input);
}

int	checkentry(char *file)
{
	int		check;
	char	symbols[3];

	check = 0;
	check = number_check(file);
	if (check == 0)
		return (0);
	check = symbols_check(file);
	if (check == 0)
		return (0);
	get_symbols(file, symbols);
	check = map_check(file, symbols);
	if (check == 0)
		return (0);
	return (check);
}

int	main(int argc, char **argv)
{
	int	i;
	int	print;

	i = 0;
	while (i < (argc - 1))
	{
		if (checkentry(argv[1 + i]))
		{
			solve_map(argv[1 + i]);
			print = 1;
		}
		else
		{
			write(1, "map error\n", 10);
		}
		i++;
	}
	return (0);
}
