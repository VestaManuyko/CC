/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:18:18 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/03 15:18:19 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_image(int y, int x, t_world *world)
{
	if (world->grid[y][x] == '1')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.wall, x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	if (world->grid[y][x] == '0')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.background, x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	if (world->grid[y][x] == 'C')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.col, x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	if (world->grid[y][x] == 'E')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->img_ptr.exit, x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	if (world->grid[y][x] == 'P')
		mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
			world->player.frames[world->player.frame],
			x * TILE_SIZE, y * TILE_SIZE);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
}

void	draw_animation(t_world *world, t_frame cur_frame)
{
	get_player_pos(world);
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
		world->img_ptr.background,
		world->player.pos.x * TILE_SIZE,
		world->player.pos.y * TILE_SIZE);
	world->player.frame = cur_frame;
	mlx_put_image_to_window(world->mlx_ptr, world->win_ptr,
		world->player.frames[world->player.frame],
		world->player.pos.x * TILE_SIZE,
		world->player.pos.y * TILE_SIZE);
	mlx_do_sync(world->mlx_ptr);
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	usleep(10000);
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
	mlx_string_put(world->mlx_ptr, world->win_ptr, 1, 10, CLR, world->moves);
	return (0);
}
