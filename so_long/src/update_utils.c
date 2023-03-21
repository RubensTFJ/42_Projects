/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:52:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/04 00:24:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	key_up(int keycode, t_vars *vars)
{
	(void)vars;
	*on(keycode) = 0;
	return (1);
}

int	key_down(int keycode, t_vars *vars)
{
	(void)vars;
	*on(keycode) = 1;
	if (*on(SPACE))
		fire_dont_move(*obj_list());
	if (*on(ESC))
		end_game(vars);
	return (1);
}

void	fire_dont_move(t_list *list)
{
	while (list)
	{
		if (list->obj->id == 'M')
		{
			if (list->obj->new_pos == movement)
				list->obj->new_pos = NULL;
			else
				list->obj->new_pos = movement;
		}
		list = list->next;
	}
}

void	make_frame(t_vars *game, t_infomap *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
		{
			map->grid[i][j]->print(game, map->grid[i][j]);
		}
	}
}

void	put_active_objects(t_vars *game, t_list *list)
{
	while (list && list->obj)
	{
		if (list->obj->id)
		{
			if (list->obj->new_pos && map()->animation)
				list->obj->new_pos(game, list->obj);
			if (list->obj->print)
				list->obj->print(game, list->obj);
		}
		list = list->next;
	}
}
