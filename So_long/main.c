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

static void	get_map2(int fd, t_world *world)
{
	char	*line;
	char	*tmp;
	int		state;
	int		line_check;

	state = 0;
	line = get_next_line(fd, &state);
	if (!line)
		error_exit(2, world);
	while (line)
	{
		tmp = world->map;
		line_check = check_line(line);
		world->map = ft_strjoin(world->map, line);
		free(line);
		free(tmp);
		if (!world->map)
			exit_perror("Error\nReason", world);
		if (!line_check)
			world->bad_lines++;
		line = get_next_line(fd, &state);
	}
	if (state != 2)
		error_exit(1, world);
}

static void	get_map(int fd, t_world *world)
{
	world->bad_lines = 0;
	world->map = ft_strdup("");
	if (!world->map)
		exit_perror("Error\nReason", world);
	get_map2(fd, world);
	if (world->bad_lines != 0)
		clean_up(world, MAP, EXIT_FAILURE);
	valid_map(world);
}

static int	valid_file(char *file)
{
	size_t	len;
	int		diff;

	len = ft_strlen(file);
	if (len < 10)
		return (0);
	diff = ft_strncmp(file + (len - 4), ".ber", 4);
	if (!diff)
		return (1);
	else
		return (0);
}

void	game_loop(int fd, t_world *world)
{
	int	x;
	int	y;

	get_map(fd, world);
	world->mlx_ptr = NULL;
	world->mlx_ptr = mlx_init();
	if (!world->mlx_ptr)
	{
		perror("Error\nMlx init failure");
		clean_up(world, ALL, EXIT_FAILURE);
	}
	x = world->grid_size.x * TILE_SIZE;
	y = world->grid_size.y * TILE_SIZE;
	world->win_ptr = mlx_new_window(world->mlx_ptr, x, y, "So_long");
	if (!world->win_ptr)
	{
		perror("Error\nMlx window creation failure");
		clean_up(world, ALL, EXIT_FAILURE);
	}
	world_init(world);
	draw_world(world);
	mlx_hook(world->win_ptr, 17, 0, exit_hook, world);
	mlx_hook(world->win_ptr, 2, 1L << 0, key_hook, world);
	mlx_loop_hook(world->mlx_ptr, draw_world, world);
	mlx_loop(world->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_world	world;

	if (argc != 2)
		return (error_message(3));
	else
	{
		if (!(valid_file(argv[1])))
			return (error_message(4));
		else
		{
			world.fd = open(argv[1], O_RDONLY);
			if (world.fd < 0)
				return (error_message(5));
			struct_init(&world);
			game_loop(world.fd, &world);
		}
	}
}
