/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmanuyko <vmanuyko@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:54:21 by vmanuyko          #+#    #+#             */
/*   Updated: 2025/06/16 19:54:25 by vmanuyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx.h"
#include "printf.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

//valid_map.c && valid_map_helpers.c
int valid_map(char *map);
size_t	get_line_len(char *map);
int get_total_rows(char *map);
int wallframe_error(void);
int rectangular_error(void);
int valid_row(char *map, int i);

#endif