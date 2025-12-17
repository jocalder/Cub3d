/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:21:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 17:21:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	find_player(t_map *map, int *pos_x, int *pos_y)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player_char(map->matrix[y][x]))
			{
				*pos_x = x;
				*pos_y = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}