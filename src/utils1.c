/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 06:21:01 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 06:21:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	print_map(t_map *map)
{
	int		i = 0;

	printf("\n--- MAP (%dx%d) ---\n", map->width, map->height);
	while (i < map->height)
	{
    	printf("%s\n", map->matrix[i]);
    	i++;
	}
	printf("\n");
}

int	is_walkable(t_map *map, double x, double y)
{
	if (map->matrix[(int)y][(int)x] == '0')
		return (1);
	return (0);
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