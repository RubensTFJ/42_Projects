/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:58:22 by rteles-f          #+#    #+#             */
/*   Updated: 2023/02/27 18:59:26 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

t_object	*create_object_1(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->collide = 1;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/wall.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->data.height = obj->data.height / 16;
	obj->data.height = 64;
	obj->data.width = 64;
	obj->data.full_width = 64;
	obj->print = sprite_to_image;
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_m(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->collide = 0;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/seg_fire.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->data.height = 64;
	obj->data.width = 64;
	obj->self_space = 0.8;
	obj->data.real_size[0] = 50;
	obj->data.real_size[1] = 50;
	obj->data.full_width = 62 * 4;
	obj->x = i;
	obj->y = j;
	obj->collision = fire_collide;
	obj->set_animation = fire_set_animation;
	obj->pixel_put = transparent_pixel_put;
	return (obj);
}

t_object	*create_object_p(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->collide = 1;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/swimmer.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->data.height = 32;
	obj->data.width = 48;
	obj->self_space = 0.5;
	obj->data.real_size[0] = 28;
	obj->data.real_size[1] = 44;
	obj->data.full_width = 32 * 4;
	obj->new_pos = movement;
	obj->collision = player_collide;
	obj->set_animation = player_set_animation;
	obj->pixel_put = transparent_pixel_put;
	obj->x = i;
	obj->y = j;
	return (obj);
}

t_object	*create_object_e(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/exit_pointer.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->x = i;
	obj->y = j;
	obj->print = NULL;
	obj->pixel_put = transparent_pixel_put;
	return (obj);
}

t_object	*create_object_c(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->collide = 1;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/addressult.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->data.real_size[0] = 64;
	obj->data.real_size[1] = 42;
	obj->pixel_put = transparent_pixel_put;
	obj->x = i;
	obj->y = j;
	return (obj);
}
