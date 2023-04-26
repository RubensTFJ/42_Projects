/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:13:24 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/26 10:21:38 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <ft_printf.h>
# include <mlx.h>
# include <sys/time.h>
# include <math.h>

# define ESC	65307
# define S		115
# define D      100
# define W      119
# define A      97
# define SPACE	32
# define SCALE	64

# define COLLECT_BURN 2
# define PLAYER_BURN 3
# define WIN 4

typedef struct s_list	t_list;
typedef struct s_object	t_object;
typedef struct s_vars	t_vars;
typedef unsigned long	t_ulong;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		real_size[2];
	int		full_width;
	int		full_height;
}	t_data;

struct	s_vars {
	void	*mlx;
	void	*win;
	int		key;
	t_data	img;
};

struct	s_object {
	int			id;
	char		collide;
	float		self_space;
	double		x;
	double		y;
	void		(*new_pos)(t_vars *vars, t_object *obj);
	void		(*print)(t_vars *vars, t_object *obj);
	int			(*collision)(t_object *obj, t_object *target);
	void		(*set_animation)(t_object *obj, u_long time, int animation);
	void		(*pixel_put)(t_data *data, int x, int y, int color);
	t_data		data;
	t_object	*on_top;
	int			animation_pos[2];
	u_long		animation_time;
};

struct s_list {
	t_object	*obj;
	t_list		*next;
};

typedef struct map_struct {
	char		**map;
	t_object	***grid;
	int			game;
	int			width_x;
	int			height_y;
	int			exit[2];
	int			pstart[2];
	int			collectables[2];
	u_long		time;
	int			typed;
	t_object	*counter;
	char		animation;
}	t_infomap;

t_infomap	*map(void);
t_infomap	*init_mapstruct(t_infomap *map);

char		*get_next_line(int fd);
int			check_map(char *file, t_infomap *vmap);
int			check_name(char *name);
int			fill_map(t_infomap *vmap, char *line, int fd, int pos);
int			check_square(t_infomap *vmap);
int			check_border(t_infomap *vmap);
int			check_characters(t_infomap *vmap);
int			characters_errors(t_infomap *vmap);
int			is_valid_character(t_infomap *vmap, char c, int i, int j);
void		check_reach(t_infomap *info, int i, int j);
int			check_reached(t_infomap *vmap);
int			is_in_str(char c, char *string);
int			bl_strlen(char *string);
int			ft_strlen(char *str);
void		*ft_calloc(size_t n, size_t xsize);

int			end_game(t_vars *vars);
void		free_map(t_infomap *map);
void		free_matrix(t_vars *game, t_infomap *map);
void		free_list(t_vars *game, t_list *list);

void		init_floor_objects(t_vars *vars, t_infomap *map);
t_object	*object_type(t_vars *vars, int id, int i, int j);
t_object	*create_object_1(t_vars *vars, int id, int i, int j);
t_object	*create_object_0(t_vars *vars, int id, int i, int j);
t_object	*create_object_p(t_vars *vars, int id, int i, int j);
t_object	*create_object_e(t_vars *vars, int id, int i, int j);
t_object	*create_object_c(t_vars *vars, int id, int i, int j);
t_object	*create_object_m(t_vars *vars, int id, int i, int j);
void		set_new_object(t_object *obj);

int			my_mlx_pixel_get(t_data *data, int x, int y);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		transparent_pixel_put(t_data *data, int x, int y, int color);
void		fire_set_animation(t_object *image, u_long time, int animation);
void		player_set_animation(t_object *image, u_long time, int animation);
void		sprite_to_image(t_vars *game, t_object *obj);
void		make_frame(t_vars *vars, t_infomap *map);

void		movement(t_vars *vars, t_object *obj);
void		verify_position(t_object *obj, t_object ***grid,
				double x, double y);
int			player_collide(t_object *obj, t_object *target);
int			fire_collide(t_object *obj, t_object *target);
float		pixel_collision(t_object *obj, t_object *target);

char		*on(int press);
t_list		**obj_list(void);

void		put_active_objects(t_vars *game, t_list *list);
void		fire_dont_move(t_list *list);
int			key_down(int keycode, t_vars *vars);
int			key_up(int keycode, t_vars *vars);
void		pop_exit(t_list *list);
void		burn(t_vars *vars, t_object *obj);

void		init_game(t_vars *game);
void		end_game_message(int status);
void		print_movement(float origin[2], float x, float y);
int			wall_check(t_object *obj, t_object ***grid);

t_list		*ft_lstnew(t_object *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		obj_stack_remove(t_object *list, t_object *remove);
void		obj_stack_add(t_object *list, t_object *add);

void		ft_print_moves(t_vars *game);
char		*sttc_itoa(int number);
u_long		get_time(void);

#endif