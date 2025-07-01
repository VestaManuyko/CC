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
    int state;

    len = 0;
    state = 0;
    world->map = ft_strdup("");
    if (!world->map)
    {
        perror("Error\nReason");
        exit(1);
    }
    while ((line = get_next_line(fd, &state)) != NULL)
    {
        tmp = world->map;
        world->map = ft_strjoin(world->map, line);
        free(line);
        free(tmp);
        if (!world->map)
        {
            perror("Error\nReason");
            exit (1);
        }
    }
    if (state != 2)
    {
        write(2, "Error\nReason: get_next_line failed\n", 36);
        exit(1);
    }
    valid_map(world);
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

int key_hook(int keycode, void *param)
{
    t_world *world;

    world = param;
    if (keycode == KEY_ESC)
        clean_up(world, ALL, EXIT_SUCCESS);
    return (0);
}

// int loop_hook(void *param)
// {
    
// }

void    game_loop(int fd, t_world *world)
{
    int x;
    int y;

    get_map(fd, world);
    world->mlx_ptr = mlx_init();
    x = world->grid_size.x * TILE_SIZE;
    y = world->grid_size.y * TILE_SIZE;
    world->win_ptr = mlx_new_window(world->mlx_ptr, x, y, "So_long");
    mlx_key_hook(world->win_ptr, key_hook, world);
    //mlx_loop_hook(world->mlx_ptr, loop_hook, world);
    mlx_loop(world->mlx_ptr);
}

int main(int argc, char **argv)
{
    int fd;
    t_world world;

    if (argc != 2)
        return (error_message(3));
    else
    {
        if (!(valid_file(argv[1])))
            return (error_message(4));
        else
        {
            fd = open(argv[1], O_RDONLY);
            if (fd < 0)
                return (error_message(5));
            game_loop(fd, &world);
            if (world.map)
                printf("The map:\n%s", world.map);
            clean_up(&world, ALL, EXIT_SUCCESS);
        }
    }
}