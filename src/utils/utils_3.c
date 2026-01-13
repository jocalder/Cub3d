/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:21:53 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/13 13:32:13 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	is_spacetab(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	flood_fill(t_map map, int y, int x, int *error)
{
	if (*error)
		return ;
	if (y < 0 || y >= map.height || x < 0 || x >= map.width)
	{
		*error = 1;
		return ;
	}
	if (map.cpy_map[y][x] == ' ' || map.cpy_map[y][x] == '\0')
	{
		*error = 1;
		return ;
	}
	if (map.cpy_map[y][x] == '1' || map.cpy_map[y][x] == 'F')
		return ;
	map.cpy_map[y][x] = 'F';
	flood_fill(map, y + 1, x, error);
	flood_fill(map, y - 1, x, error);
	flood_fill(map, y, x + 1, error);
	flood_fill(map, y, x - 1, error);
}

static int	is_validate_character(int c)
{
	if (!is_spacetab(c) && !is_player_char(c) && c != '1' && c != '0')
		return (0);
	return (1);
}

int	validate_characters(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!is_validate_character(map->matrix[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
