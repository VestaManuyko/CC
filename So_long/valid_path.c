/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:12:04 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/23 11:12:11 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int collectible_check(int x, int y)
{
    int col;

    col = 0;
    if (grid[x][y] == '1' || grid[x][y] == 'S' || grid[x][y] == 'E')
        return (col);
    if (grid[x][y] == 'C')
        col++;
    grid[x][y] = 'S';
    return (col);
}

int reachable_exit(int x, int y)
{
    //go trough the grid from start.player.pos 
    //and see if exit is reachable after collecting all col
    // if found return (1); else return (0);
}

int valid_path(t_world *world)


