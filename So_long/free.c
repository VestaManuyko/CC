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

static void	free_grid(t_world *world)
{
	int	y;

	y = 0;
	if (!world->grid)
		return ;
	while (y < world->grid_size.y)
	{
		if (world->grid[y])
			free(world->grid[y]);
		y++;
	}
	free(world->grid);
	world->grid = NULL;
}

static void	free_copy(t_world *world)
{
	int	y;

	y = 0;
	if (!world->copy)
		return ;
	while (y < world->grid_size.y)
	{
		if (world->copy[y])
			free(world->copy[y]);
		y++;
	}
	free(world->copy);
	world->copy = NULL;
}

static void	clean_windows(t_world *world)
{
	if (world->img_ptr.background)
		mlx_destroy_image(world->mlx_ptr, world->img_ptr.background);
	if (world->img_ptr.wall)
		mlx_destroy_image(world->mlx_ptr, world->img_ptr.wall);
	if (world->img_ptr.player)
		mlx_destroy_image(world->mlx_ptr, world->img_ptr.player);
	if (world->img_ptr.exit)
		mlx_destroy_image(world->mlx_ptr, world->img_ptr.exit);
	if (world->img_ptr.col)
		mlx_destroy_image(world->mlx_ptr, world->img_ptr.col);
	if (world->win_ptr)
		mlx_destroy_window(world->mlx_ptr, world->win_ptr);
	mlx_destroy_display(world->mlx_ptr);
	free(world->mlx_ptr);
}

static void	free_map(t_world *world)
{
	if (world->map)
		free(world->map);
	if (world->bad_lines != 0)
		write(2, "Error\nWrong char in the map\n", 28);
	world->map = NULL;
}

//check what needs to be freed based on enum passed as parameters
//takes pointers from world struct and calls needed helpers
void	clean_up(t_world *world, int clean, int do_exit)
{
	if (do_exit != NO_EXIT)
	{
		close (world->fd);
		world->fd = -1;
	}
	if (clean == MAP)
		free_map(world);
	if (clean == GRID)
		free_grid(world);
	if (clean == COPY)
		free_copy(world);
	if (clean == ALL)
	{
		free_map(world);
		free_grid(world);
		free_copy(world);
		if (world->mlx_ptr)
			clean_windows(world);
	}
	if (do_exit == EXIT_FAILURE)
		exit (1);
	else if (do_exit == EXIT_SUCCESS)
		exit (0);
}
