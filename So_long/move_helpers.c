/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 20:18:10 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 20:18:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_col(t_world *world)
{
	world->player.col_col++;
	if (world->player.col_col == world->collectibles)
		world->player.allow_exit = 1;
}

void	check_exit(t_world *world)
{
	if (world->player.allow_exit == 1)
		clean_up(world, ALL, EXIT_SUCCESS);
}
