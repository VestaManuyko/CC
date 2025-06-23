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

static int	rectangular_map(char *map, t_world *world)
{
	size_t	i;
	size_t	line_len;
	size_t	cur_line_len;

	i = 0;
	cur_line_len = 0;
	line_len = get_line_len(map);
    world->grid_size.x = line_len;
	while (map[i])
	{
		cur_line_len++;
		if (map[i++] == '\n')
		{
			if (cur_line_len != line_len)
                return (error_message(2));
			cur_line_len = 0;
		}
	}
    if (map[i - 1] != '\n')
    {
        if (++cur_line_len != line_len)
            return (error_message(2));
    }
	return (1);
}

static int	valid_wallframe(char *map, t_world *world)
{
    size_t  i;
    int     row;

    i = 0;
    row = 1;
    while (map[i])
    {
        if (row == 1 || row == get_total_rows(map, world))
        {
            i = valid_edge_row(map, i);
            if (!i)
                return (error_message(1));
            row++;
        }
        else
        {
            i = valid_mid_row(map, i);
            if (!i)
                return (0);
            row++;
        }
        i++;
    }
    return (1);
}

static int  valid_composition(char *map, t_world *world)
{
    size_t  i;
    int     start;
    int     exit;

    i = 0;
    start = 0;
    exit = 0;
    while (map[i])
    {
        if (map[i] == 'P')
            start++;
        if (map[i] == 'E')
            exit++;
        if (map[i] == 'C')
            world->collectibles++;
        i++;
    }
    if (start != 1 || exit != 1 || world->collectibles == 0)
    {
        write (2, "Error\nNon-valid composition\n", 29);
        return (0);
    }
    return (1);
}

int	valid_map(char *map, t_world *world)
{
    if (!map || !*map)
	{
		write (2, "Error\nEmpty file\n", 18);
		return (0);
	}
	if (!rectangular_map(map, world))
		return (0);
    if (!valid_composition(map, world))
        return (0);
    if (!valid_wallframe(map, world))
        return (0);
    else
	    return (1);
}
