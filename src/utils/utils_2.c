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

void	validate_identifiers(t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea)
		exit_error("No textures");
	if (map->floor_color == -1 || map->ceiling_color == -1)
		exit_error("No colors");
}

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

void	free_map(char **map, int height)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (i < height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->win.width || y >= cub->win.height)
		return ;
	dst = cub->mlx.img.addr
		+ (y * cub->mlx.img.line_len + (x * cub->mlx.img.bpp / 8));
	*(unsigned int *)dst = color;
}
