/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:34:50 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/17 22:35:09 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	check_map(char *file, t_infomap *vmap)
{
	int			fd;

	if (!check_name(file))
		return (0);
	fd = open(file, O_RDONLY);
	fill_map(vmap, get_next_line(fd), fd, 0);
	close(fd);
	if (vmap->map)
	{
		if (!check_square(vmap) || !check_border(vmap)
			|| !check_characters(vmap))
			free_map(vmap);
		else
		{
			check_reach(vmap, vmap->pstart[0], vmap->pstart[1]);
			if (!check_reached(vmap))
				free_map(vmap);
		}
	}
	return ((!!vmap->map));
}

int	check_name(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len < 5)
	{
		ft_printf("Invalid Map: File Name Invalid.\n");
		return (0);
	}
	len--;
	if (name[len] != 'r' || name[len - 1] != 'e'
		|| name[len - 2] != 'b' || name[len - 3] != '.')
	{
		ft_printf("Invalid Map: File Name Invalid.\n");
		return (0);
	}
	return (1);
}

/* The function will take the first length as a rule,
and proceed to compare it to every other line.
If a difference is found, false is returned.
*/
int	check_square(t_infomap *vmap)
{
	int	i;

	vmap->width_x = bl_strlen(vmap->map[0]);
	i = 1;
	while (i < vmap->height_y)
	{
		if (bl_strlen(vmap->map[i++]) != vmap->width_x)
		{
			ft_printf("Invalid Map: Map Isn't Square.");
			return (0);
		}
	}
	return (1);
}

/* A loop will run through the, (top and bottom line)/(First and Last column)
 while the char's are equal to '1' aka 'Walls'.
It will then check If the loop was able to get to the end of the Matrix,
by comparing the loop value to
the length/height of the matrix.info->map[i + 1][j] += 1;
*/
int	check_border(t_infomap *vmap)
{
	int	i;

	i = 0;
	while (vmap->map[0][i] == '1' &&
		vmap->map[(vmap->height_y - 1)][i] == '1')
		i++;
	if (i != vmap->width_x)
	{
		ft_printf("Invalid Map: Map Not Surrounded by '1'.\n");
		return (0);
	}
	i = 0;
	while (vmap->map[i] && vmap->map[i][0] == '1' &&
		vmap->map[i][(vmap->width_x - 1)] == '1')
		i++;
	if (i != vmap->height_y)
	{
		ft_printf("Invalid Map: Map Not Surrounded by '1'.\n");
		return (0);
	}
	return (1);
}

int	check_characters(t_infomap *vmap)
{
	int	i;
	int	j;

	i = -1;
	while (vmap->map[++i])
	{
		j = -1;
		while (vmap->map[i][++j])
		{
			if (!is_valid_character(vmap, vmap->map[i][j], i, j))
			{
				ft_printf("Invalid Map: Invalid Character ''%c'' \
on map: %i, %i.\n", vmap->map[i][j], i, j);
				return (0);
			}
			if (vmap->map[i][j] != '1' && vmap->map[i][j] != '\n'
				&& vmap->map[i][j] != 'P')
				vmap->map[i][j] -= 1;
		}
	}
	return (characters_errors(vmap));
}
