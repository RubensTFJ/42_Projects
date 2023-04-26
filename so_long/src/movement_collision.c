/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_collision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:31:52 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/17 13:31:52 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

float	pixel_collision(t_object *obj, t_object *target)
{
	float	x;
	float	y;
	float	distance;
	float	space;

	space = obj->self_space;
	if (obj->y > target->y)
		space = target->self_space;
	x = (obj->x) - (target->x);
	y = (obj->y) - (target->y);
	x *= x;
	y *= y;
	distance = sqrt(x + y);
	if (distance < space)
		return (distance);
	return (0);
}

int	wall_check(t_object *obj, t_object ***grid)
{
	if ((grid[(int)obj->x][(int)obj->y]->id == '1') \
	|| (grid[(int)(obj->x + ((float)obj->data.real_size[1] / SCALE))] \
	[(int)obj->y]->id == '1') \
	|| (grid[(int)obj->x] \
	[(int)(obj->y + ((float)obj->data.real_size[0] / SCALE))]->id == '1')
	|| (grid[(int)(obj->x + ((float)obj->data.real_size[1] / SCALE))] \
	[(int)(obj->y + ((float)obj->data.real_size[0] / SCALE))]->id == '1'))
		return (1);
	return (0);
}

int	fire_collide(t_object *obj, t_object *target)
{
	if (target->id == '0')
		return (0);
	if (target->id == '1')
		return (wall_check(obj, map()->grid));
	else if (target->id == 'P')
	{
		if (pixel_collision(obj, target))
			map()->game = PLAYER_BURN;
	}
	else if (target->id == 'M')
	{
		if (pixel_collision(obj, target))
			return (1);
	}
	else if (target->id == 'C' && pixel_collision(obj, target))
		map()->game = COLLECT_BURN;
	return (0);
}

int	player_collide(t_object *obj, t_object *target)
{
	if (target->id == '0')
		return (0);
	if (target->id == '1')
		return (wall_check(obj, map()->grid));
	else if (target->id == 'M')
	{
		if (pixel_collision(obj, target))
			map()->game = PLAYER_BURN;
	}
	else if (target->id == 'C' && pixel_collision(obj, target))
	{
		target->id = 0;
		map()->collectables[1]--;
		if (!map()->collectables[1])
			pop_exit(*obj_list());
		obj_stack_remove(map()->grid[(int)target->x][(int)target->y], target);
		target->on_top = NULL;
	}
	else if (target->id == 'E' && !map()->collectables[1]
		&& pixel_collision(obj, target))
		map()->game = WIN;
	return (0);
}

// int	player_collide(t_object *obj, t_object *target)
// {
// 	(void)obj;
// 	if (target->id == '0')
// 		return (0);
// 	if (target->id == '1')
// 		return (1);
// 	else if (target->id == 'M')
// 	{
// 		if (pixel_collision(obj, target))
// 			map()->game = PLAYER_BURN;
// 	}
// 	else if (target->id == 'C')
// 	{
// 		target->id = 0;
// 		map()->collectables[1]--;
// 		if (!map()->collectables[1])
// 			pop_exit(*obj_list());
// 		obj_stack_remove(map()->grid[(int)target->x][(int)target->y], target);
// 		target->on_top = NULL;
// 	}
// 	else if (target->id == 'E' && !map()->collectables[1])
// 		map()->game = WIN;
// 	return (0);
// }
