/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:26:27 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 17:26:28 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_up(t_world *world)
{
	int	x;
	int	y;

	x = world->player.pos.x;
	y = world->player.pos.y;
	if (world->grid[y - 1][x] == '1')
		return ;
	if (world->grid[y - 1][x] == 'C')
	{
		set_col(world);
		world->grid[y - 1][x] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.y--;
	}
	if (world->grid[y - 1][x] == 'E')
		check_exit(world);
	if (world->grid[y - 1][x] == '0')
	{
		world->grid[y - 1][x] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.y--;
	}
}

static void	move_left(t_world *world)
{
	int	x;
	int	y;

	x = world->player.pos.x;
	y = world->player.pos.y;
	if (world->grid[y][x - 1] == '1')
		return ;
	if (world->grid[y][x - 1] == 'C')
	{
		set_col(world);
		world->grid[y][x - 1] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.x--;
	}
	if (world->grid[y][x - 1] == 'E')
		check_exit(world);
	if (world->grid[y][x - 1] == '0')
	{
		world->grid[y][x - 1] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.x--;
	}
}

void	move_right(t_world *world)
{
	int	x;
	int	y;

	x = world->player.pos.x;
	y = world->player.pos.y;
	if (world->grid[y][x + 1] == '1')
		return ;
	if (world->grid[y][x + 1] == 'C')
	{
		set_col(world);
		world->grid[y][x + 1] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.x++;
	}
	if (world->grid[y][x + 1] == 'E')
		check_exit(world);
	if (world->grid[y][x + 1] == '0')
	{
		world->grid[y][x + 1] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.x++;
	}
}

void	move_down(t_world *world)
{
	int	x;
	int	y;

	x = world->player.pos.x;
	y = world->player.pos.y;
	if (world->grid[y + 1][x] == '1')
		return ;
	if (world->grid[y + 1][x] == 'C')
	{
		set_col(world);
		world->grid[y + 1][x] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.y++;
	}
	if (world->grid[y + 1][x] == 'E')
		check_exit(world);
	if (world->grid[y + 1][x] == '0')
	{
		world->grid[y + 1][x] = 'P';
		world->grid[y][x] = '0';
		world->player.steps++;
		world->player.pos.y++;
	}
}

void	move_player(t_world *world, int keycode)
{
	if (keycode == KEY_W)
	{
		draw_animation(world, MOVE_UP);
		remove_old_pos(world);
		move_up(world);
		world->player.frame = STAND_BACK;
	}
	if (keycode == KEY_A)
	{
		draw_animation(world, MOVE_LEFT);
		remove_old_pos(world);
		move_left(world);
		world->player.frame = STAND_LEFT;
	}
	move_player2(world, keycode);
	moves_update(world);
}
