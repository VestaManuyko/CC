/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:11:17 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/03 15:11:18 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

# define MAP 6
# define GRID 7
# define COPY 8
# define ALL 9
# define NO_EXIT 3

# define TILE_SIZE 16
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define CLR 0x00F0FF00

typedef enum s_frame
{
	STAND,
	MOVE_DOWN,
	MOVE_RIGHT,
	STAND_RIGHT,
	MOVE_LEFT,
	STAND_LEFT,
	MOVE_UP,
	STAND_BACK
}	t_frame;

typedef struct s_coord
{
	int	y;
	int	x;
}	t_coord;

typedef struct s_img
{
	void	*col;
	void	*wall;
	void	*exit;
	void	*background;
}	t_img;

typedef struct s_player
{
	t_frame	frame;
	t_coord	pos;
	void	*frames[8];
	int		col_col;
	int		allow_exit;
	int		steps;
}	t_player;

typedef struct s_world
{
	char		**grid;
	char		*map;
	char		**copy;
	t_coord		grid_size;
	int			collectibles;
	t_player	player;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img_ptr;
	char		*moves;
	int			bad_lines;
	int			fd;
}	t_world;

//valid_map.c
void	valid_map(t_world *world);
//valid_map_helpers.c
size_t	get_line_len(char *map);
int		get_total_rows(t_world *world);
int		error_message(int n);
size_t	valid_edge_row(t_world *world, size_t i);
size_t	valid_mid_row(t_world *world, size_t i);
//valid_path.c
int		valid_path(t_world *world);
void	get_player_pos(t_world *world);
//grid_handling.c
void	create_grid(t_world *world);
void	copy_grid(t_world *world);
//free.c
void	clean_up(t_world *world, int clean, int exit);
//free_helpers.c
void	free_map(t_world *world);
//hooks.c
int		key_hook(int keycode, void *param);
int		exit_hook(void *param);
//init.c
void	world_init(t_world *world);
//draw.c
int		draw_world(t_world *world);
void	draw_animation(t_world *world, t_frame cur_frame);
//move.c
void	move_player(t_world *world, int keycode);
void	move_right(t_world *world);
void	move_down(t_world *world);
//move_helpers.c
void	set_col(t_world *world);
void	check_exit(t_world *world);
void	moves_update(t_world *world);
void	move_player2(t_world *world, int keycode);
void	remove_old_pos(t_world *world);
//line.c
void	exit_perror(const char *s, t_world *world);
int		check_line(char *line);
void	error_exit(int n, t_world *world);
void	struct_init(t_world *world);

#endif