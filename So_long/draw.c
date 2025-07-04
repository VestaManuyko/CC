/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:38:39 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 14:38:40 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(int y, int x, t_world *world)
{
	if (world->grid[y][x] == '1')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.wall, x * TILE_SIZE, y * TILE_SIZE);
	if (world->grid[y][x] == '0')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.background, x * TILE_SIZE, y * TILE_SIZE);
	if (world->grid[y][x] == 'C')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.col, x * TILE_SIZE, y * TILE_SIZE);
	if (world->grid[y][x] == 'E')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.exit, x * TILE_SIZE, y * TILE_SIZE);
	if (world->grid[y][x] == 'P')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.player, x * TILE_SIZE, y * TILE_SIZE);
}

int	draw_world(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	while (y < world->grid_size.y)
	{
		x = 0;
		while (x < world->grid_size.x)
		{
			put_image(y, x, world);
			x++;
		}
		y++;
	}
	return (0);
}
