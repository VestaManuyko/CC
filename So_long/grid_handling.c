/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:28:09 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/23 13:28:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//for mem allocation for copy_grid
static char	**create_copy(t_world *world)
{
	int	y;

	y = 0;
	world->copy = ft_calloc(world->grid_size.y, sizeof(char *));
	if (!world->copy)
	{
		perror("Error\nCreation of copy_grid failed");
		clean_up(world, ALL, EXIT_FAILURE);
	}
	while (y < world->grid_size.y)
	{
		world->copy[y] = ft_calloc(world->grid_size.x, sizeof(char));
		if (!world->copy[y])
			exit_perror("Error\nCreation of copy_grid failed", world);
		y++;
	}
	return (world->copy);
}

//copy from og grid to copy grid for check_path later
//so that we can change the copy grid but save og grid
void	copy_grid(t_world *world)
{
	int	y;
	int	x;

	y = 0;
	create_copy(world);
	while (y < world->grid_size.y)
	{
		x = 0;
		while (x < world->grid_size.x)
		{
			world->copy[y][x] = world->grid[y][x];
			x++;
		}
		y++;
	}
}

//from map_str to map_grid (og storage for the game_grid)
static void	init_grid(t_world *world)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (world->map[i] && y < world->grid_size.y)
	{
		x = 0;
		while (world->map[i] && x < world->grid_size.x)
		{
			if (world->map[i] != '\n')
			{
				world->grid[y][x] = world->map[i];
				x++;
			}
			i++;
		}
		y++;
	}
}

// create_grid allocates memory for our grid and calls init_grid
void	create_grid(t_world *world)
{
	int	y;

	y = 0;
	world->grid = ft_calloc(world->grid_size.y, sizeof(char *));
	if (!world->grid)
	{
		perror("Error\nCreation of grid failed");
		clean_up(world, MAP, EXIT_FAILURE);
	}
	while (y < world->grid_size.y)
	{
		world->grid[y] = NULL;
		world->grid[y] = ft_calloc(world->grid_size.x, sizeof(char));
		if (!world->grid[y])
			exit_perror("Error\nCreation of grid failed", world);
		y++;
	}
	init_grid(world);
}
