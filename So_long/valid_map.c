/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:53:53 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/18 18:04:51 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static int	rectangular_map(t_world *world)
{
	size_t	i;
	size_t	line_len;
	size_t	cur_line_len;

	i = 0;
	cur_line_len = 0;
	line_len = get_line_len(world->map);
	world->grid_size.x = line_len -1;
	while (world->map[i])
	{
		cur_line_len++;
		if (world->map[i++] == '\n')
		{
			if (cur_line_len != line_len)
				return (error_message(2));
			cur_line_len = 0;
		}
	}
	if (world->map[i - 1] != '\n')
	{
		if (++cur_line_len != line_len)
			return (error_message(2));
	}
	return (1);
}

static int	valid_wallframe(t_world *world)
{
	size_t	i;
	int		row;

	i = 0;
	row = 1;
	while (world->map[i])
	{
		if (row == 1 || row == get_total_rows(world))
		{
			i = valid_edge_row(world, i);
			if (!i)
				return (error_message(1));
			row++;
		}
		else
		{
			i = valid_mid_row(world, i);
			if (!i)
				return (0);
			row++;
		}
		i++;
	}
	return (1);
}

static int	valid_composition(t_world *world)
{
	size_t	i;
	int		start;
	int		exit;

	i = 0;
	start = 0;
	exit = 0;
	world->collectibles = 0;
	while (world->map[i])
	{
		if (world->map[i] == 'P')
			start++;
		if (world->map[i] == 'E')
			exit++;
		if (world->map[i] == 'C')
			world->collectibles += 1;
		i++;
	}
	if (start != 1 || exit != 1 || world->collectibles == 0)
	{
		write (2, "Error\nNon-valid composition\n", 29);
		return (0);
	}
	return (1);
}

void	valid_map(t_world *world)
{
	if (!world->map || !world->map[0])
	{
		write (2, "Error\nNo map\n", 14);
		clean_up(world, MAP, EXIT_FAILURE);
	}
	if (!rectangular_map(world) || !valid_composition(world)
		|| !valid_wallframe(world))
		clean_up(world, MAP, EXIT_FAILURE);
	if (!valid_path(world))
		clean_up(world, ALL, EXIT_FAILURE);
	else
		return ;
}
