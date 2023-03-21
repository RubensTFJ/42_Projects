/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:30:18 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/04 00:09:55 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

/* Uses get_next_line recursively until it recieves a empty line.
When a Empty line is found (get_next_line found end of file), 
the program uses the 'pos' variable,
that has been past on to count the recursive loop, to create a 
exact size of array.
The function then goes back pointing the line to their specific
 position in the array.
*/
int	fill_map(t_infomap *vmap, char *line, int fd, int pos)
{
	if (!line)
	{
		if (pos > 0)
			vmap->map = ft_calloc(sizeof(char *), (pos + 1));
		vmap->height_y = pos;
	}
	else
		if (fill_map(vmap, get_next_line(fd), fd, (pos + 1)))
			vmap->map[pos] = line;
	return ((!!vmap->map));
}

/* The Function will check if the positions Up, Down, 
Left and Right exists and if they are "Walkable".
If they are, it will proceed to call itself on to 
all of those positions, but first it will change the char
to an "Unwalkable" character. 
It will count the Collectables that it found, 
and change the path to their original value by adding 1.
*/
void	check_reach(t_infomap *info, int i, int j)
{
	if ((i + 1) < info->height_y && is_in_str(info->map[i + 1][j], "/DBL"))
	{
		info->collectables[1] += (info->map[i + 1][j] == 'B');
		info->map[i + 1][j] += 1;
		check_reach(info, (i + 1), j);
	}
	if ((i - 1) >= 0 && is_in_str(info->map[i - 1][j], "/DBL"))
	{
		info->collectables[1] += (info->map[i - 1][j] == 'B');
		info->map[i - 1][j] += 1;
		check_reach(info, (i - 1), j);
	}
	if ((j + 1) < info->width_x && is_in_str(info->map[i][j + 1], "/DBL"))
	{
		info->collectables[1] += (info->map[i][j + 1] == 'B');
		info->map[i][j + 1] += 1;
		check_reach(info, i, (j + 1));
	}
	if ((j - 1) >= 0 && is_in_str(info->map[i][j - 1], "/DBL"))
	{
		info->collectables[1] += (info->map[i][j - 1] == 'B');
		info->map[i][j - 1] += 1;
		check_reach(info, i, (j - 1));
	}
}

int	check_reached(t_infomap *vmap)
{
	if (vmap->collectables[0] != vmap->collectables[1]
		|| vmap->map[vmap->exit[0]][vmap->exit[1]] != 'E')
	{
		ft_printf("Invalid Map: Can't Reach Variables.\n");
		return (0);
	}
	return (1);
}

/* The function will identify if the Char is among the 5 possible chars.
if its a 'C'ollectable, it will keep count of how many.
If its a 'P'layerStart, it will save its position after making sure a 
previous 'P' hasn't been found.
If its a 'E'xit, it will save its position after making sure a 
previous 'E' hasn't been found.
And lastly if all cases fail, it will check if it is among the rest 
of possible Characters.
*/
int	is_valid_character(t_infomap *vmap, char c, int i, int j)
{
	if (c == 'C')
	{
		vmap->collectables[0]++;
		return (1);
	}
	if (c == 'P' && vmap->pstart[0] > -1)
		return (0);
	else if (c == 'P')
	{
		vmap->pstart[0] = i;
		vmap->pstart[1] = j;
		return (1);
	}
	if (c == 'E' && vmap->exit[0] > -1)
		return (0);
	else if (c == 'E')
	{
		vmap->exit[0] = i;
		vmap->exit[1] = j;
		return (1);
	}
	if (is_in_str(c, "01M\n"))
		return (1);
	return (0);
}

int	characters_errors(t_infomap *vmap)
{
	if (vmap->pstart[0] < 0)
	{
		ft_printf("Invalid Map: Invalid Character - No 'P' on Map.");
		return (0);
	}
	if (vmap->exit[0] < 0)
	{
		ft_printf("Invalid Map: Invalid Character - No 'E' on Map.");
		return (0);
	}
	if (vmap->collectables[0] == 0)
	{
		ft_printf("Invalid Map: Invalid Character - No 'C' on Map.");
		return (0);
	}
	return (1);
}
