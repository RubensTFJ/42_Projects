/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:11:43 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/10 18:52:21 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	sprite_to_image(t_vars *game, t_object *obj)
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (obj->set_animation)
		obj->set_animation(obj, get_time(), map()->animation);
	x = obj->x * SCALE;
	y = obj->y * SCALE;
	i = -1;
	while (++i < obj->data.height)
	{
		j = -1;
		while (++j < obj->data.width)
			obj->pixel_put(&game->img, (y + i), (x + j),
				my_mlx_pixel_get(&obj->data, (i + obj->animation_pos[1]),
					(obj->animation_pos[0] + j)));
	}
}

void	fire_set_animation(t_object *image, u_long time, int animation)
{
	(void)animation;
	if ((time - image->animation_time) > 50)
	{
		image->animation_pos[1] += image->data.height;
		if (image->animation_pos[1] >= image->data.full_width)
		{
			image->animation_pos[1] = 0;
			image->animation_pos[0] += image->data.width;
			if (image->animation_pos[0] >= 192)
				image->animation_pos[0] = 0;
		}
		image->animation_time = time;
	}
}

void	player_set_animation(t_object *obj, u_long time, int animation)
{
	if (*on(D))
		obj->animation_pos[0] = obj->data.width * 2;
	else if (*on(A))
		obj->animation_pos[0] = obj->data.width * 1;
	else if (*on(S))
		obj->animation_pos[0] = 0;
	else if (*on(W))
		obj->animation_pos[0] = obj->data.width * 3;
	if (animation && ((time - obj->animation_time) > 150))
	{
		obj->animation_pos[1] += obj->data.height;
		if (obj->animation_pos[1] > obj->data.full_width)
			obj->animation_pos[1] = 0;
		obj->animation_time = time;
	}
	else if (!animation)
	{
		obj->animation_pos[0] = 0;
		obj->animation_pos[1] = 0;
	}
}
