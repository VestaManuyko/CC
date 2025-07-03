/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:50:55 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/03 14:50:56 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	image_error(t_world *world)
{
	perror("Error\nImage creation failure");
	clean_up(world, ALL, EXIT_FAILURE);
}

static void	init_player(t_world *world)
{
	int	x;
	int	y;

	world->img_ptr.player = mlx_xpm_file_to_image(world->mlx_ptr,
			"textures/player/stand.xpm", &x, &y);
	if (!world->img_ptr.player)
		image_error(world);
}

void	world_init(t_world *world)
{
	int	x;
	int	y;

	world->steps = 0;
	world->player.col_col = 0;
	world->player.allow_exit = 0;
	world->img_ptr.background = mlx_xpm_file_to_image(world->mlx_ptr,
			"textures/other/background.xpm", &x, &y);
	if (!world->img_ptr.background)
		image_error(world);
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
	init_player(world);
}
