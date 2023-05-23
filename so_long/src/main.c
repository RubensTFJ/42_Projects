/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:14:14 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/22 15:35:32 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	update(t_vars *game)
{
	map()->animation = *on(W) + *on(A) + *on(S) + *on(D);
	if (get_time() - map()->time > 20)
	{
		map()->time = get_time();
		make_frame(game, map());
		put_active_objects(game, *obj_list());
		mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	}
	ft_print_moves(game);
	if (map()->game != 1)
	{
		end_game_message(map()->game);
		end_game(game);
	}
	return (0);
}

void	init_hooks(t_vars *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_down, game);
	mlx_hook(game->win, 3, 1L << 1, key_up, game);
	mlx_hook(game->win, 17, 1L << 17, end_game, game);
	mlx_loop_hook(game->mlx, update, game);
}

void	init_game(t_vars *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (map()->width_x * SCALE),
			(map()->height_y * SCALE + 64), "The Piscine Experience!");
	game->img.img = mlx_new_image(game->mlx, (map()->width_x * SCALE),
			(map()->height_y * SCALE));
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
}

int	main(int argc, char **argv)
{
	static t_vars	game;

	if (argc != 2 || !check_map(argv[1], init_mapstruct(map())))
		return (0);
	init_game(&game);
	init_floor_objects(&game, map());
	init_hooks(&game);
	mlx_loop(game.mlx);
}

/*
	mlx_init
	
	mlx_put_image_to_window
	mlx_xpm_file_to_image10000000100001000111000010010001
	mlx_destroy_image
	mlx_xpm_to_image
	mlx_new_image
	mlx_pixel_put
	
	mlx_destroy_display
	mlx_clear_window
	mlx_new_window
	
	mlx_do_sync
	
	mlx_get_color_value
	mlx_get_screen_size
	mlx_get_data_addr
	
	mlx_do_key_autorepeatoff
	mlx_do_key_autorepeaton
	
	mlx_expose_hook
	mlx_key_hook
	mlx_hook
	
	mlx_loop_end
	mlx_loop
	
	mlx_mouse_get_pos
	mlx_mouse_hide
	mlx_mouse_hook
	mlx_mouse_move
	mlx_mouse_show
	
	mlx_string_put
	mlx_set_font
	MLX_H
*/