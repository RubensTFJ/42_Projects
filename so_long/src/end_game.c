/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:54:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/17 15:22:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_matrix(t_vars *game, t_infomap *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height_y)
	{
		j = -1;
		while (++j < map->width_x)
		{
			mlx_destroy_image(game->mlx, map->grid[i][j]->data.img);
			free(map->grid[i][j]);
		}
		free(map->grid[i]);
	}
	free(map->grid);
}

void	free_list(t_vars *game, t_list *list)
{
	if (list->next)
		free_list(game, list->next);
	mlx_destroy_image(game->mlx, list->obj->data.img);
	free(list->obj);
	free(list);
	list = NULL;
}

int	end_game(t_vars *game)
{
	free_list(game, *obj_list());
	free_matrix(game, map());
	free_map(map());
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	pop_exit(t_list *list)
{
	while (list->obj->id != 'E')
		list = list->next;
	if (list->obj->id == 'E')
		list->obj->print = sprite_to_image;
}

void	end_game_message(int status)
{
	if (status == COLLECT_BURN)
		ft_printf("Address SIGSEGV\n");
	if (status == PLAYER_BURN)
		ft_printf("Player SIGSEGV\n");
	if (status == WIN)
		ft_printf("Program Completed. No errors Detected.\n");
}
