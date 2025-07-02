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

void    player_init2(t_world *world)
{
    int x;
    int y;

    world->player.frames[4] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/move_left.xpm", &x, &y);
    if (!world->player.frames[4])
        image_error(world);
    world->player.frames[5] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/stand_right.xpm", &x, &y);
    if (!world->player.frames[5])
        image_error(world);
    world->player.frames[6] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/move_up.xpm", &x, &y);
    if (!world->player.frames[6])
        image_error(world);
    world->player.frames[7] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/stand_back.xpm", &x, &y);
    if (!world->player.frames[7])
        image_error(world);
}

void    player_init(t_world *world)
{
    int x;
    int y;
    
    world->player.frame = 0;
    world->player.frames[0] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/stand.xpm", &x, &y);
    if (!world->player.frames[0])
        image_error(world);
    world->player.frames[1] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/move_down.xpm", &x, &y);
    if (!world->player.frames[1])
        image_error(world);
    world->player.frames[2] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/move_right.xpm", &x, &y);
    if (!world->player.frames[2])
        image_error(world);
    world->player.frames[3] = mlx_xpm_file_to_image(world->mlx_ptr, 
        "textures/player/stand_right.xpm", &x, &y);
    if (!world->player.frames[3])
        image_error(world);
    player_init2(world);
}

void    world_init(t_world *world)
{
    int x;
    int y;

    world->steps = 0;
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
    player_init(world);
}