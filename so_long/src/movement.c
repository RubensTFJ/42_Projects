/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:49 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/26 09:45:13 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_collision(t_object *obj, t_object *target)
{
	int	ans;

	ans = 0;
	while (target)
	{
		ans += obj->collision(obj, target);
		target = target->on_top;
	}
	return (ans);
}

void	print_movement(float origin[2], float x, float y)
{
	if (origin[0] != x || origin[1] != y)
	{
		map()->typed++;
	}
}

void	verify_position(t_object *obj, t_object ***grid, double x, double y)
{
	int		i;
	int		j;
	float	save[2];

	save[0] = obj->x;
	save[1] = obj->y;
	obj->x = x;
	obj->y = y;
	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
		{
			if ((((int)x + i) > -1) && (((int)y + j) > -1)
				&& is_collision(obj, grid[(int)x + i][(int)y + j]))
			{
				obj->x = save[0];
				obj->y = save[1];
				return ;
			}
		}
	}
	if (obj->id == 'P' && (save[0] != x || save[1] != y))
		map()->typed++;
}

void	movement(t_vars *vars, t_object *obj)
{
	double		x;
	double		y;
	float		walk;

	(void)vars;
	walk = 0.09;
	if (map()->animation > 1)
		walk *= 0.85;
	x = obj->x + ((*on(S) - *on(W)) * walk);
	y = obj->y + ((*on(D) - *on(A)) * walk);
	obj_stack_remove(map()->grid[(int)(obj->x)][(int)(obj->y)], obj);
	obj->on_top = NULL;
	verify_position(obj, map()->grid, x, obj->y);
	verify_position(obj, map()->grid, obj->x, y);
	obj_stack_add(map()->grid[(int)(obj->x)][(int)(obj->y)], obj);
}

// void	verify_position(t_object *obj, t_object ***grid, double x, double y)
// {
// 	int	move;
//
// 	move = 0;
// 	if (!is_collision(obj, grid[(int)x][(int)obj->y]) &&
// 	!is_collision(obj, grid[(int)(x + ((float)obj->data.real_size[1] / SCALE))]
// 	[(int)obj->y]) && !is_collision(obj, grid[(int)x][(int)
// 	(obj->y + ((float)obj->data.real_size[0] / SCALE))]) &&
// 	!is_collision(obj, grid[(int)(x + ((float)obj->data.real_size[1] / SCALE))]
// 	[(int)(obj->y + ((float)obj->data.real_size[0] / SCALE))])
// 	&& obj->x != x && ++move)
// 		obj->x = x;
// 	if (!is_collision(obj, grid[(int)obj->x][(int)y]) && \/
// 	!is_collision(obj, grid[(int)
// 	(obj->x + ((float)obj->data.real_size[1] / SCALE))][(int)y]) &&
// 	!is_collision(obj, grid[(int)obj->x][(int)
// 	(y + ((float)obj->data.real_size[0] / SCALE))]) && \/
// 	!is_collision(obj, grid[(int)
// 	(obj->x + ((float)obj->data.real_size[1] / SCALE))][(int)
// 	(y + ((float)obj->data.real_size[0] / SCALE))]) && obj->y != y && ++move)
// 		obj->y = y;
// 	if (move && (obj->id == 'P'))
// 	{
// 		map()->typed++;
// 		ft_printf("moves: %i\n", map()->typed);
// 	}
// }
// void	burn(t_vars *vars, t_object *obj)
// {
// 	(void)vars;
// 	obj_stack_remove(map()->grid[(int)(obj->x)][(int)(obj->y)], obj);
// 	obj->on_top = NULL;
// 	verify_position(obj, map()->grid, obj->x, obj->y);
// 	obj_stack_add(map()->grid[(int)(obj->x)][(int)(obj->y)], obj);
// }