/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:46 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/11 16:21:47 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(t_world *world)
{
	if (world->map)
		free(world->map);
	if (world->bad_lines != 0)
		write(2, "Error\nWrong char in the map\n", 28);
	world->map = NULL;
}
