/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:43:34 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/07/04 16:43:34 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_perror(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

int	check_line(char *line)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(line);
	while (i < (len - 1))
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'E' && line[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(int n)
{
	if (n == 1)
	{
		write(2, "Error\nReason: get_next_line failed\n", 36);
		exit(1);
	}
	if (n == 2)
	{
		write(2, "Error\nInvalid map composition\n", 31);
		exit(1);
	}
}
