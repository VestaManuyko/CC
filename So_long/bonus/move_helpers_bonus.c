/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:18:10 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 20:18:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_col(t_world *world)
{
	world->player.col_col++;
	if (world->player.col_col == world->collectibles)
		world->player.allow_exit = 1;
}

void	check_exit(t_world *world)
{
	if (world->player.allow_exit == 1)
		clean_up(world, ALL, EXIT_SUCCESS);
}

void	moves_update(t_world *world)
{
	if (world->moves)
	{
		free(world->moves);
		world->moves = NULL;
	}
	world->moves = ft_itoa(world->player.steps);
	if (!world->moves)
		clean_up(world, ALL, EXIT_FAILURE);
}

void	remove_old_pos(t_world *world)
{
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
		world->img_ptr.background,
		world->player.pos.x * TILE_SIZE,
		world->player.pos.y * TILE_SIZE);
}

void	move_player2(t_world *world, int keycode)
{
	if (keycode == KEY_S)
	{
		draw_animation(world, MOVE_DOWN);
		remove_old_pos(world);
		move_down(world);
		world->player.frame = STAND;
	}
	if (keycode == KEY_D)
	{
		draw_animation(world, MOVE_RIGHT);
		remove_old_pos(world);
		move_right(world);
		world->player.frame = STAND_RIGHT;
	}
}
