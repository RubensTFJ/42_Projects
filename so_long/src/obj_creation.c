/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:22:57 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/06 16:48:36 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	init_floor_objects(t_vars *vars, t_infomap *map)
{
	int	i;
	int	j;

	map->grid = calloc(sizeof(t_object *), map->height_y);
	i = -1;
	while (++i < map->height_y)
	{
		map->grid[i] = calloc(sizeof(t_object *), map->width_x);
		j = -1;
		while (++j < map->width_x)
		{
			if (map->map[i][j] == '1' || map->map[i][j] == '/')
				map->grid[i][j] = create_object_1(vars, '1', i, j);
			else
			{
				map->grid[i][j] = create_object_0(vars, '0', i, j);
				map->grid[i][j]->on_top
					= object_type(vars, map->map[i][j], i, j);
				ft_lstadd_back(obj_list(), ft_lstnew(map->grid[i][j]->on_top));
			}
		}
	}
}

t_object	*object_type(t_vars *vars, int id, int i, int j)
{
	if (id == '1')
		return (create_object_1(vars, id, i, j));
	else if (id == 'C')
		return (create_object_c(vars, id, i, j));
	else if (id == 'P')
		return (create_object_p(vars, id, i, j));
	else if (id == 'E')
		return (create_object_e(vars, id, i, j));
	else if (id == 'M')
		return (create_object_m(vars, id, i, j));
	return (NULL);
}

t_object	*create_object_0(t_vars *vars, int id, int i, int j)
{
	t_object	*obj;

	obj = ft_calloc(sizeof(t_object), 1);
	set_new_object(obj);
	obj->id = id;
	obj->data.img = mlx_xpm_file_to_image(vars->mlx, "sprites/ground.xpm",
			&obj->data.width, &obj->data.height);
	obj->data.addr = mlx_get_data_addr(obj->data.img, &obj->data.bits_per_pixel,
			&obj->data.line_length, &obj->data.endian);
	obj->x = i;
	obj->y = j;
	return (obj);
}

void	set_new_object(t_object *obj)
{
	obj->new_pos = NULL;
	obj->print = NULL;
	obj->data.addr = NULL;
	obj->data.img = NULL;
	obj->on_top = NULL;
	obj->self_space = 1;
	obj->print = sprite_to_image;
	obj->pixel_put = my_mlx_pixel_put;
}
