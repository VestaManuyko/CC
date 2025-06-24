/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:12:04 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/23 11:12:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int collectible_check(char **copy, int y, int x)
{
    int col;

    col = 0;
    if (copy[x][y] == '1' || copy[x][y] == 'S' || copy[x][y] == 'E')
        return (col);
    if (copy[x][y] == 'C')
        col++;
    copy[x][y] = 'S';
    return (col);
}

static int reachable_exit(int x, int y)
{
    return (0);
    //go trough the grid from start.player.pos 
    //and see if exit is reachable after collecting all col
    // if found return (1); else return (0);
}

static void get_player_pos(t_world *world)
{
    int y;
    int x;

    y = 0;
    while (y <= world->grid_size.y)
    {
        x = 0;
        while (x <= world->grid_size.x)
        {
            if (world->grid[y][x] == 'P')
            {
                world->player_pos.x = x;
                world->player_pos.y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}

int valid_path(char *map, t_world *world)
{
    char **copy;
    int col;

    create_grid(world, map);
    copy = copy_grid(world);
    get_player_pos(world);
    col = collectible_check(copy, world->player_pos.y, world->player_pos.x);
    if (col != world->collectibles)
        return (0);
    
}