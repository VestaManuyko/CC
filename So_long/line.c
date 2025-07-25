/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:20:27 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/04 16:20:28 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	while (i < (len - 1))
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}

void	exit_perror(const char *s, t_world *world)
{
	perror(s);
	clean_up(world, ALL, EXIT_FAILURE);
}

void	error_exit(int n, t_world *world)
{
	if (n == 1)
	{
		write(2, "Error\nReason: get_next_line failed\n", 36);
		clean_up(world, MAP, EXIT_FAILURE);
	}
	if (n == 2)
	{
		write(2, "Error\nReason: no line\n", 23);
		clean_up(world, MAP, EXIT_FAILURE);
	}
}

void	struct_init(t_world *world)
{
	world->bad_lines = 0;
	world->collectibles = 0;
	world->copy = NULL;
	world->grid = NULL;
	world->map = NULL;
	world->mlx_ptr = NULL;
	world->steps = 0;
	world->win_ptr = NULL;
	world->img_ptr.background = NULL;
	world->img_ptr.col = NULL;
	world->img_ptr.exit = NULL;
	world->img_ptr.player = NULL;
	world->img_ptr.wall = NULL;
}
