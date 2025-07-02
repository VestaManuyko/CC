/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:37:51 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 12:37:52 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void    image_error(t_world *world)
{
    perror("Error\nImage creation failure");
    clean_up(world, ALL, EXIT_FAILURE);
}

void    image_init(t_world *world)
{
    int x;
    int y;

    world->img_ptr.wall = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/other/wall.xpm", &x, &y);
    if (!world->img_ptr.wall)
        image_error(world);
    world->img_ptr.col = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/other/col.xpm", &x, &y);
    if (!world->img_ptr.col)
        image_error(world);
    world->img_ptr.exit = mlx_xpm_file_to_image(world->mlx_ptr,
        "textures/other/crystal.xpm", &x, &y);
    if (!world->img_ptr.exit)
        image_error(world);
}