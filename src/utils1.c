/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:05:04 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:05:04 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	is_walkable(t_map *map, double x, double y)
{
	int		map_x;
	int		map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_x >= map->width
		|| map_y >= map->height)
		return (0);
	if (map->matrix[map_y][map_x] != '0')
		return (0);
	return (1);
}

void	close_program(t_cub *cub)
{
	if (cub->mlx.img.ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img.ptr);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	free_map(cub->map.matrix, cub->map.height);
	exit(0);
}

int	parse_value(char **str)
{
	int		value;

	value = 0;
	if (!ft_isdigit(**str))
		return (-1);
	while (ft_isdigit(**str))
	{
		value = value * 10 + (**str - '0');
		(*str)++;
	}
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}
