/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:57:36 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/16 19:57:37 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *get_map(int fd, t_world *world)
{
    char    *line;
    char    *tmp;
    size_t  len;

    len = 0;
    world->map = ft_strdup("");
    if (!world->map)
    {
        perror("Error\nReason");
        return (NULL);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        tmp = world->map;
        world->map = ft_strjoin(world->map, line);
        free(line);
        free(tmp);
        if (!world->map)
        {
            perror("Error\nReason");
            return (NULL);
        }
    }
    if (!(valid_map(world->map, world)))
    {
        free (world->map);
        return (NULL);
    }
    return (world->map);
}

static int valid_file(char *file)
{
    size_t  len;
    int     diff;

    len = ft_strlen(file);
    if (len < 5)
        return (0);
    diff = ft_strncmp(file + (len - 4), ".ber", 4);
    if (!diff)
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    int fd;
    char *map;
    t_world world;

    if (argc != 2)
    {
        write(2, "Error\nIncorrect input! Expected 2 arguments\n", 45);
        return (1);
    }
    else
    {
        if (!(valid_file(argv[1])))
        {
            write (2, "Error\nIncorrect filename\n", 26);
            return (1);
        }
        else
        {
            fd = open(argv[1], O_RDONLY);
            if (fd < 0)
            {
                perror("Error\nOpening file failed");
                return (1);
            }
            map = get_map(fd, &world);
            if (!map)
                return (1);
            printf("The map:\n%s", map);
            free (map);
            //FIX add clean exit of the shell by exit 1 if errors
        }
    }
}