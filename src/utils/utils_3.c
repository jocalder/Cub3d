/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:21:53 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/13 17:30:02 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	is_spacetab(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
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
			if (!is_player_char(map->matrix[y][x])
				&& !is_spacetab(map->matrix[y][x])
				&& map->matrix[y][x] != '0' && map->matrix[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
