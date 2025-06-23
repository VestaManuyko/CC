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

#include "mlx.h"
#include "printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

//valid_map.c
int valid_map(char *map);
//valid_map_helpers.c
size_t	get_line_len(char *map);
int get_total_rows(char *map);
int error_message(int n);
size_t valid_edge_row(char *map, size_t i);
size_t  valid_mid_row(char *map, size_t i);
//valid_path.c
int valid_path(t_world *world);
//grid_handling.c
void    create_grid(t_world *world, char *map);

typedef struct s_coord
{
    int y;
    int x;
}   t_coord;

typedef struct s_world
{
    char    **grid;
    t_coord grid_size;
    int     collectibles;
    t_coord player_pos;
}   t_world;

#endif