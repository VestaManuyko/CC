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

#include "so_long.h";

int ft_check_map()

int ft_check_ber_file(char *file)
{
    size_t  len;
    int diff;

    len = ft_strlen(file);
    diff = ft_strncmp(file + (len - 4), ".ber", 4);
    if (!diff)
        return (1);
    else
        return (0);
}

int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        write(2, "Error\nIncorrect input! Expected 2 arguments", 46);
        return (1);
    }
    else
    {
        if (!ft_check_ber_file(argv[2]))
        {
            write (2, "Error\nIncorrect file, expected .ber\n", 37);
            return (1);
        }
        else
        {
            fd = open(argv[2], O_RDONLY);
            if (fd != 0)
            {
                perror("Error\n");
                return (1);
            }
        }
    }
}