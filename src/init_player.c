/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                     	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:21:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 17:21:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	validate_player(t_map *map, int *pos_x, int *pos_y)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (is_player_char(map->matrix[y][x]))
			{
				count++;
				if (count == 1)
				{
					*pos_x = x;
					*pos_y = y;
				}
				else
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (count);
}

