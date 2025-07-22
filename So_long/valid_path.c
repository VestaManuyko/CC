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
//gets players start position
static void	get_player_pos(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < world->grid_size.y)
	{
		x = 0;
		while (x < world->grid_size.x)
		{
			if (world->grid[y][x] == 'P')
			{
				world->player.pos.x = x;
				world->player.pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// flood filling algorithm used to check all the walkable paths etc.
static int	col_check(t_world *world, int y, int x, int *col)
{
	if (y < 0 || x < 0 || y >= world->grid_size.y || x >= world->grid_size.x)
		return (0);
	if (world->copy[y][x] == '1' || world->copy[y][x] == 'S'
		|| world->copy[y][x] == 'E')
		return (0);
	if (world->copy[y][x] == 'C')
		(*col)++;
	world->copy[y][x] = 'S';
	col_check(world, y, x +1, col);
	col_check(world, y, x -1, col);
	col_check(world, y +1, x, col);
	col_check(world, y -1, x, col);
	return (0);
}

static int	exit_check(t_world *world, int y, int x, int *ex)
{
	if (y < 0 || x < 0 || y >= world->grid_size.y || x >= world->grid_size.x)
		return (0);
	if (world->copy[y][x] == '1' || world->copy[y][x] == 'D')
		return (0);
	if (world->copy[y][x] == 'E')
		(*ex)++;
	world->copy[y][x] = 'D';
	exit_check(world, y, x +1, ex);
	exit_check(world, y, x -1, ex);
	exit_check(world, y +1, x, ex);
	exit_check(world, y -1, x, ex);
	return (0);
}

int	valid_path(t_world *world)
{
	int	col;
	int	ex;

	col = 0;
	ex = 0;
	create_grid(world);
	get_player_pos(world);
	copy_grid(world);
	col_check(world, world->player.pos.y,
		world->player.pos.x, &col);
	exit_check(world, world->player.pos.y,
		world->player.pos.x, &ex);
	if (col != world->collectibles || ex != 1)
	{
		write(2, "Error\nNo valid path in the map\n", 32);
		return (0);
	}
	clean_up(world, COPY, NO_EXIT);
	return (1);
}
