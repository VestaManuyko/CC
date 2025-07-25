/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:54:21 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/16 19:54:25 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

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
	void	*player;
}	t_img;

typedef struct s_player
{
	t_coord	pos;
	int		col_col;
	int		allow_exit;
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
	int			steps;
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
//grid_handling.c
void	create_grid(t_world *world);
void	copy_grid(t_world *world);
//free.c
void	clean_up(t_world *world, int clean, int exit);
//hooks.c
int		key_hook(int keycode, void *param);
int		exit_hook(void *param);
//init.c
void	world_init(t_world *world);
//draw.c
int		draw_world(t_world *world);
//move.c
void	move_player(t_world *world, int keycode);
//move_helpers.c
void	set_col(t_world *world);
void	check_exit(t_world *world);
//line.c
int		check_line(char *line);
void	exit_perror(const char *s, t_world *world);
void	error_exit(int n, t_world *world);
void	struct_init(t_world *world);

#endif