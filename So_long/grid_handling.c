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
// create_grid allocates memory for our grid and initializes it
void    create_grid(t_world *world, char *map)
{
    int y;

    y = 0;
    world->grid = malloc(sizeof(char *) * world->grid_size.y);
    if (!world->grid)
    {
        perror("Error\nCreation of grid failed");
        exit(1);
    }
    while (y < world->grid_size.y)
    {
        world->grid[y] = malloc(sizeof(char) * world->grid_size.x);
        if (!world->grid[y])
        {
            perror("Error\nCreation of grid failed");
            exit(1);
        }
        y++;
    }
    init_grid(world, map);
}