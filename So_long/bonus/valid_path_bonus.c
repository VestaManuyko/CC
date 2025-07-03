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

#include "so_long_bonus.h"
//gets players start position
static void get_player_pos(t_world *world)
{
    int y;
    int x;

    y = 0;
    while (y < world->grid_size.y)
    {
        x = 0;
        while (x < world->grid_size.x)
        {
            if (world->grid[y][x] == 'P')
            {
                world->player.pos.x = x;
                world->player.pos.y = y;
                return ;
            }
            x++;
        }
        y++;
    }
}
// flood filling algorithm used to check all the walkable paths etc.
static int path_check(t_world *world, char **copy, int y, int x, int *col)
{
    if (y < 0 || x < 0 || y > world->grid_size.y || x > world->grid_size.x)
        return (0);
    if (copy[y][x] == '1' || copy[y][x] == 'S')
        return (0);
    if (copy[y][x] == 'C')
        (*col)++;
    if (copy[y][x] == 'E')
        (*col)++;
    copy[y][x] = 'S';
    if (path_check(world, copy, y, x + 1, col) ||
        path_check(world, copy, y, x - 1, col) ||
        path_check(world, copy, y + 1, x, col) ||
        path_check(world, copy, y - 1, x, col))
        return (1);
    if ((*col) == world->collectibles + 1)
        return (1);
    else
        return (0);
}

int valid_path(t_world *world)
{
    char **copy;
    int col;

    col = 0;
    create_grid(world);
    get_player_pos(world);
    copy_grid(world);
    copy = world->copy;
    if (!path_check(world, copy, world->player.pos.y, 
        world->player.pos.x, &col))
    {
        write(2, "Error\nNo valid path in the map\n", 32);
        return (0);
    }
    else
    {
        clean_up(world, COPY, NO_EXIT);
        return (1);
    }
    }
        