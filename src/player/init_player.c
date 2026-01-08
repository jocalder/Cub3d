/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:11 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:11 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	validate_player(t_map *map, int *pos_x, int *pos_y)
{
	int		x;
	int		y;
	int		count;

	count = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
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
		}
	}
	return (count);
}

static void	init_player_north_south(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	init_player_west_east(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

static void	init_player_direction(t_cub *cub)
{
	init_player_north_south(&cub->player);
	init_player_west_east(&cub->player);
}

void	init_player(t_cub *cub, t_map *map)
{
	int		x;
	int		y;
	int		count;

	count = validate_player(map, &x, &y);
	if (count != 1)
		exit_error("Map must contain one player");
	cub->player.pos_x = x + 0.5;
	cub->player.pos_y = y + 0.5;
	cub->player.dir = map->matrix[y][x];
	map->matrix[y][x] = '0';
	init_player_direction(cub);
}
