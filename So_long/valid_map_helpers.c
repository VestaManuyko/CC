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
#include "so_long.h"

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

int error_message(int n)
{
    if (n == 1)
        write(2, "Error\nIncorrect wallframe\n", 27);
    else if (n == 2)
        write (2, "Error\nInvalid map: not rectangular\n", 36);
    return (0);
}

int get_total_rows(char *map, t_world *world)
{
    size_t  i;
    int     total_rows;

    i = 0;
    total_rows = 0;
    while (map[i])
    {
        if (map[i] == '\n')
            total_rows++;
        i++;      
    }
    if (map[i - 1] != '\n')
        total_rows++;
    world->grid_size.y = total_rows;
    return (total_rows);
}

size_t valid_edge_row(char *map, size_t i)
{
    while (map[i] && map[i] != '\n')
    {
        if (map[i] != '1')
        {
            return (0);
        }
        i++;
    }
    return (i);
}

size_t  valid_mid_row(char *map, size_t i)
{
    if (map[i - 1] == '\n')
    {
        if (map[i] != '1')
            return (error_message(1));
    }
    while (map[i + 1] && map[i + 1] != '\n')
        i++;
    if (map[i] != '\n' && (map[i + 1] == '\n' || map[i + 1] == 0))
    {
        if (map[i] != '1')
            return (error_message(1));
    }
    return (i);
}