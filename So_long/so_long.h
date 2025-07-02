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
# include <stdlib.h>

# define MAP 6
# define GRID 7
# define COPY 8
# define ALL 9
# define NO_EXIT 3

# define TILE_SIZE 16
# define KEY_ESC 65307

typedef struct s_coord
{
    int y;
    int x;
}   t_coord;

typedef struct s_img
{
    void    *col;
    void    *wall;
    void    *exit;
    void    *background;
}   t_img;

typedef enum    s_frame
{
    STAND,
    MOVE_RIGHT,
    STAND_RIGHT,
    MOVE_LEFT,
    STAND_LEFT,
    MOVE_UP,
    STAND_BACK,
    MOVE_DOWN
}   t_frame;

typedef struct s_player
{
    t_frame frame;
    t_coord pos;
    void   *frames[8];
}   t_player;

typedef struct s_world
{
    char    **grid;
    char    *map;
    char    **copy;
    t_coord grid_size;
    int     collectibles;
    t_player player;
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img_ptr;
}   t_world;

//valid_map.c
void valid_map(t_world *world);
//valid_map_helpers.c
size_t	get_line_len(char *map);
int get_total_rows(t_world *world);
int error_message(int n);
size_t valid_edge_row(t_world *world, size_t i);
size_t  valid_mid_row(t_world *world, size_t i);
//valid_path.c
int valid_path(t_world *world);
//grid_handling.c
void    create_grid(t_world *world);
void    copy_grid(t_world *world);
//free.c
void clean_up(t_world *world, int clean, int exit);
//hooks.c
int key_hook(int keycode, void *param);
int exit_hook(void *param);
//image_handling.c
void    image_init(t_world *world);
//draw.c
void    draw_world(t_world *world);

#endif