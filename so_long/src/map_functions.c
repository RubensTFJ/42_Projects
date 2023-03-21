/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:42:02 by rteles-f          #+#    #+#             */
/*   Updated: 2023/01/27 13:33:04 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_map(t_infomap *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}

// -1 tem motivo, outra funçao usa como sinalizaçao
t_infomap	*init_mapstruct(t_infomap *map)
{
	map->game = 1;
	map->pstart[0] = -1;
	map->pstart[1] = -1;
	map->exit[0] = -1;
	map->exit[1] = -1;
	map->map = NULL;
	map->grid = NULL;
	map->width_x = -1;
	map->height_y = -1;
	map->collectables[0] = 0;
	map->collectables[1] = 0;
	map->time = get_time();
	return (map);
}
