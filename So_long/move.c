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

#include "so_long.h"

void	move_up(t_world *world)
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
		world->steps++;
		world->player.pos.y--;
	}
	if (world->grid[y - 1][x] == 'E')
		check_exit(world);
	if (world->grid[y - 1][x] == '0')
	{
		world->grid[y - 1][x] = 'P';
		world->grid[y][x] = '0';
		world->steps++;
		world->player.pos.y--;
	}
}

void	move_left(t_world *world)
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
		world->steps++;
		world->player.pos.x--;
	}
	if (world->grid[y][x - 1] == 'E')
		check_exit(world);
	if (world->grid[y][x - 1] == '0')
	{
		world->grid[y][x - 1] = 'P';
		world->grid[y][x] = '0';
		world->steps++;
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
		world->steps++;
		world->player.pos.x++;
	}
	if (world->grid[y][x + 1] == 'E')
		check_exit(world);
	if (world->grid[y][x + 1] == '0')
	{
		world->grid[y][x + 1] = 'P';
		world->grid[y][x] = '0';
		world->steps++;
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
		world->steps++;
		world->player.pos.y++;
	}
	if (world->grid[y + 1][x] == 'E')
		check_exit(world);
	if (world->grid[y + 1][x] == '0')
	{
		world->grid[y + 1][x] = 'P';
		world->grid[y][x] = '0';
		world->steps++;
		world->player.pos.y++;
	}
}

void	move_player(t_world *world, int keycode)
{
	if (keycode == KEY_W)
		move_up(world);
	if (keycode == KEY_A)
		move_left(world);
	if (keycode == KEY_S)
		move_down(world);
	if (keycode == KEY_D)
		move_right(world);
	ft_printf("\rNumber of steps made: %u", world->steps);
}
