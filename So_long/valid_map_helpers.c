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

int wallframe_error(void)
{
    write(2, "Error\nIncorrect wallframe\n", 29);
    return (0);
}

int get_total_rows(char *map)
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
    return (total_rows);
}

int valid_row(char *map, int i)
{
    while (map[i] && map[i] != '\n')
    {
        if (map[i] != '1')
            return (0);
        i++;
    }
    return (i);
}