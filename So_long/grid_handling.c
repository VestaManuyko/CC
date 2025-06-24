/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:28:09 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/23 13:28:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//copy from og grid to copy grid for check_path later
//so that we can change the copy grid but save og grid
char    **copy_grid(t_world *world)
{
    char    **copy[world->grid_size.y][world->grid_size.x];
    int     y;
    int     x;

    y = 0;
    while (y <= world->grid_size.y)
    {
        x = 0;
        while (x <= world->grid_size.x)
        {
            copy[y][x] = world->grid[y][x];
            x++;
        }
        y++;
    }
    return (copy);
}
//from map_str to map_grid (og storage for the game_grid)
static void    init_grid(t_world *world, char *map)
{
    int x;
    int y;
    int i;

    y = 0;
    i = 0;
    while (map[i] && y <= world->grid_size.y)
    {
        x = 0;
        while (map[i] && x <= world->grid_size.x)
        {
            if (map[i] != '\n')
                world->grid[y][x] = map[i];
            x++;
            i++;
        }
        y++;
    }
}

// create_grid allocates memory for our grid and calls init_grid
void    create_grid(t_world *world, char *map)
{
    int y;

    y = 0;
    world->grid = malloc(sizeof(char *) * world->grid_size.y);
    if (!world->grid)
    {
        perror("Error\nCreation of grid failed");
        free (map);
        exit(1);
    }
    while (y < world->grid_size.y)
    {
        world->grid[y] = malloc(sizeof(char) * world->grid_size.x);
        if (!world->grid[y])
        {
            perror("Error\nCreation of grid failed");
            free (map);
            exit(1);
        }
        y++;
    }
    init_grid(world, map);
}