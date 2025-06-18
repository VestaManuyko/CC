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

static int	rectangular_map(char *map)
{
	size_t	i;
	size_t	line_len;
	size_t	cur_line_len;

	i = 0;
	cur_line_len = 0;
	line_len = get_line_len(map);
	while (map[i])
	{
		cur_line_len++;
		if (map[i++] == '\n')
		{
			if (cur_line_len != line_len)
			{
				write (2, "Error\nInvalid map: not rectangular\n", 35);
				return (0);
			}
			cur_line_len = 0;
		}
	}
	return (1);
}

static int	valid_wallframe(char *map)
{
    size_t  i;
    int     row;

    i = 0;
    row = 1;
    while (map[i])
    {
        if (row == 1 || row == get_total_rows(map))
        {
            i = valid_row(map, i);
            if (!i)
                return (wallframe_error());
            row++;
        }
        else
        {
            if (map[i - 1] == '\n' || map[(i++) + 1] == '\n')
            {
                if (map[i] != '1')
                    return (wallframe_error());
            }
            row++;
        }
    }
    return (1);
}

static int  valid_composition(char *map)
{
    size_t  i;
    int     start;
    int     exit;
    int     collectible;

    i = 0;
    start = 0;
    exit = 0;
    collectible = 0;
    while (map[i])
    {
        if (map[i] == 'P')
            start++;
        if (map[i] == 'E')
            exit++;
        if (map[i] == 'C')
            collectible++;
        i++;
    }
    if (start != 1 || exit != 1 || collectible == 0)
    {
        write (2, "Error\nNon-valid composition\n", 29);
        return (0);
    }
    return (1);
}

int	valid_map(char *map)
{
    if (!map || !*map)
	{
		write (2, "Error\nEmpty file\n", 18);
		return (0);
	}
	if (!rectangular_map(map))
		return (0);
    if (!valid_composition(map))
        return (0);
    if (!valid_wallframe(map))
        return (0);
    else
	    return (1);
}
