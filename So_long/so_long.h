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

# define TILE_SIZE 32

typedef struct s_coord
{
    int y;
    int x;
}   t_coord;

typedef struct s_world
{
    char    **grid;
    char    *map;
    char    **copy;
    t_coord grid_size;
    int     collectibles;
    t_coord player_pos;
    void    *mlx_ptr;
    void    *win;
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

#endif