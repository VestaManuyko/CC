/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:39:06 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/26 13:39:07 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    free_grid(t_world *world)
{
    int  y;

    y = 0;
    if (!world->grid)
        return ;
    while (world->grid[y])
    {
        free(world->grid[y])
        y++;
    }
    free(world->grid);
    world->grid = NULL;
    
}

static void free_copy(t_world *world)
{
    int  y;

    y = 0;
    if (!world->copy)
        return ;
    while (world->copy[y])
    {
        free(world->copy[y])
        y++;
    }
    free(world->copy);
    world->copy = NULL;
}
//check what needs to be freed based on enum passed as parameters
//takes pointers from world struct and calls needed helpers
void clean_up(t_world *world, int clean, int exit)
{
    if (clean == MAP)
    {
        if (world->map)
            free(world->map);
        world->map = NULL;
    }
    else if (clean == GRID)
    {
        free_grid(world);
    }
    else if (clean == COPY)
    {
        free_copy(world);
    }
    else if (clean == ALL)
    {
        if (world->map)
            free(world->map);
        world->map = NULL;
        free_grid(world);
        free_copy(world);
    }
    if (exit == EXIT_FAILURE)
        exit(1);
    else
        exit(0);
}