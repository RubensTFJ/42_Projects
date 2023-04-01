/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 23:48:13 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 22:05:37 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqheader.h"

typedef struct square_structure	t_square;
typedef struct table_structure	t_table;

int			get_square(int *start, int *limits, char **table, char clear);
t_square	*mallocsquare(void);
t_square	*hold_biggersquare(t_square *squareinfo, int newsize, int i, int j);
int			smaller_larger(int *steps, int size);

t_square	*run_table(char **table, int *limits, char clear)
{
	int			i;
	int			j;
	int			position[2];
	t_square	*squareinfo;
	int			newsize;

	squareinfo = mallocsquare();
	if (!squareinfo)
		return (squareinfo);
	i = -1;
	while (++i < limits[0])
	{
		j = -1;
		while (++j < limits[1])
		{
			if (table[i][j] == clear)
			{
				position[0] = i;
				position[1] = j;
				newsize = get_square(position, limits, table, clear);
				squareinfo = hold_biggersquare(squareinfo, newsize, i, j);
			}
		}
	}
	return (squareinfo);
}

t_square	*mallocsquare(void)
{
	t_square	*squareinfo;

	squareinfo = malloc(sizeof(t_square));
	if (!squareinfo)
		return (squareinfo);
	squareinfo->posx = 0;
	squareinfo->posy = 0;
	squareinfo->size = 0;
	return (squareinfo);
}

t_square	*hold_biggersquare(t_square *squareinfo, int newsize, int i, int j)
{
	if (squareinfo->size < newsize)
	{
		squareinfo->posx = i;
		squareinfo->posy = j;
		squareinfo->size = newsize;
	}
	return (squareinfo);
}

int	get_square(int *start, int *limits, char **table, char clear)
{
	int	i;
	int	j;
	int	steps[2];
	int	size;
	int	stop;

	i = start[0];
	size = 0;
	stop = limits[1];
	steps[0] = 0;
	while (i < limits[0] && table[i][start[1]] == clear)
	{
		steps[0]++;
		j = start[1];
		steps[1] = 0;
		while (j < stop && table[i][j] == clear)
		{
			j++;
			steps[1]++;
		}
		stop = start[1] + steps[1];
		size = smaller_larger(steps, size);
		i++;
	}
	return (size);
}

int	smaller_larger(int *steps, int size)
{
	int	loser;

	loser = steps[0];
	if (steps[0] > steps[1])
	{
		loser = steps[1];
	}
	if (loser > size)
	{
		return (loser);
	}
	else
	{
		return (size);
	}
}
