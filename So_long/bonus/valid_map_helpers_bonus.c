/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:00:03 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/18 19:00:05 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

size_t	get_line_len(char *map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (map[i++] == '\n')
			break ;
	}
	return (i);
}

int	error_message(int n)
{
	if (n == 1)
		write(2, "Error\nIncorrect wallframe\n", 27);
	else if (n == 2)
		write (2, "Error\nInvalid map: not rectangular\n", 36);
	else if (n == 3)
	{
		write(2, "Error\nIncorrect input! Expected 2 arguments\n", 45);
		return (1);
	}
	else if (n == 4)
	{
		write (2, "Error\nIncorrect filename\n", 26);
		return (1);
	}
	else if (n == 5)
	{
		perror("Error\nOpening file failed");
		return (1);
	}
	else if (n == 6)
		write (2, "Error\nWrong char in the map\n", 28);
	return (0);
}

int	get_total_rows(t_world *world)
{
	size_t	i;
	int		total_rows;

	i = 0;
	total_rows = 0;
	while (world->map[i])
	{
		if (world->map[i] == '\n')
			total_rows++;
		i++;
	}
	if (world->map[i - 1] != '\n')
		total_rows++;
	world->grid_size.y = total_rows;
	return (total_rows);
}

size_t	valid_edge_row(t_world *world, size_t i)
{
	while (world->map[i] && world->map[i] != '\n')
	{
		if (world->map[i] != '1')
		{
			return (0);
		}
		i++;
	}
	return (i);
}

size_t	valid_mid_row(t_world *world, size_t i)
{
	if (world->map[i - 1] == '\n')
	{
		if (world->map[i] != '1')
			return (error_message(1));
	}
	while (world->map[i + 1] && world->map[i + 1] != '\n')
		i++;
	if (world->map[i] != '\n'
		&& (world->map[i + 1] == '\n' || world->map[i + 1] == 0))
	{
		if (world->map[i] != '1')
			return (error_message(1));
	}
	return (i);
}
