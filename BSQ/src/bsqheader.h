/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsqheader.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:41:18 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 21:47:47 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQHEADER_H
# define BSQHEADER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct table_structure
{
	char	**table;
	int		*dimensions;
}	t_table;

typedef struct square_structure
{
	int		posx;
	int		posy;
	int		size;
}	t_square;

t_table		*read_file(char *file);
void		fill_table(t_table *table_ready, int fd);
t_table		*allocate_table(int *dimensions);
int			get_height(int fd);
int			get_line_size(int fd);
t_square	*run_table(char **table, int *limits, char clear);
t_square	*mallocsquare(void);
t_square	*hold_biggersquare(t_square *squareinfo, int newsize, int i, int j);
void		update_position(int *position, int i, int j);
int			get_square(int *start, int *limits, char **table, char clear);
void		putsquare(char **table, char full, t_square *squareinfo);
void		print_table(char **table, int *dimension);
void		get_symbols(char *file, char *result);
int			checkentry(char *file);
int			number_check(char *file);
int			symbols_check(char *file);
int			map_check(char *file, char *symbols);
int			check_lines_symbles(int fd, char current_char,
				char *symbols, int *lines);
int			open_check(char *file);
int			line_length(char *file);

#endif
