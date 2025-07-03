/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:39:41 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/02 12:39:41 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, void *param)
{
	t_world	*world;

	world = param;
	if (keycode == KEY_ESC)
		clean_up(world, ALL, EXIT_SUCCESS);
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
		move_player(world, keycode);
	return (0);
}

int	exit_hook(void *param)
{
	t_world	*world;

	world = param;
	clean_up(world, ALL, EXIT_SUCCESS);
	return (0);
}
