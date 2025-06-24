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

static int collectible_check(t_world *world, int x, int y)
{
    int col;

    col = 0;
    if (world->grid[x][y] == '1' || world->grid[x][y] == 'S' || world->grid[x][y] == 'E')
        return (col);
    if (world->grid[x][y] == 'C')
        col++;
    world->grid[x][y] = 'S';
    return (col);
}

static int reachable_exit(int x, int y)
{
    return (0);
    //go trough the grid from start.player.pos 
    //and see if exit is reachable after collecting all col
    // if found return (1); else return (0);
}

int valid_path(char *map, t_world *world)
{
    create_grid(world, map);
    return (1);
    // creates a copy of the grid and then with that
    //calls collectible_check in a looop an then reachable_exit
}