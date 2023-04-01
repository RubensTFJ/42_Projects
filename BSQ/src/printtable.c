/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:34:30 by rteles-f          #+#    #+#             */
/*   Updated: 2022/08/24 13:35:31 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsqheader.h"

typedef struct square_structure	t_square;
typedef struct table_structure	t_table;

void	print_table(char **table, int *dimension)
{
	int	i;
	int	j;

	i = 0;
	while (i < dimension[0])
	{
		j = 0;
		while (j < dimension[1])
		{
			write(1, &table[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	putsquare(char **table, char full, t_square *squareinfo)
{
	int	i;
	int	j;

	i = 0;
	while (i < squareinfo->size)
	{
		j = 0;
		while (j < squareinfo->size)
		{
			table[squareinfo->posx + i][squareinfo->posy + j] = full;
			j++;
		}
		i++;
	}
}
