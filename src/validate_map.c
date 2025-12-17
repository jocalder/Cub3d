/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:28:17 by marvin            #+#    #+#             */
/*   Updated: 2025/12/17 13:28:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	padding_rows(t_map *map)
{
	int		y;
	int		len;
	int		row;

	y = 0;
	while (y < map->height)
	{
		len = ft_strlen(map->matrix[y])
		if (len < map->width)
		{
			row = malloc(map->width + 1);
			if (!row)
				exit_error("Malloc error in padding");
			ft_memset(row, ' ', map->width);
			ft_memcpy(row, map->matrix[y], len);
			row[map->width] = '\0';
			free(map->matrix[y]);
			map->matrix[y] = row;
		}
		y++;
	}
}

char	**dup_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1))
	if (!copy)
		exit_error("Malloc copy map failed");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy)
			break ;
		i++;
	}
	if (i < height)
	{
		while (--i > 0)
			free(copy[i - 1])
		free(copy);
		return (NULL);
	}
	copy[height] = NULL;
	return (copy);
}

int	check_map_borders(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->width)
	{
		if (map->matrix[0][i] == '0' || is_player_char(map->matrix[0][i]))
			return (-1);
		if (map->matrix[map->height - 1][i] == '0' ||
			is_player_char(map->matrix[map->height - 1][i]))
			return (-1);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->matrix[i][0] == '0' || is_player_char(map->matrix[i][0]))
			return (-1);
		if (map->matrix[i][map->width - 1] == '0' ||
			is_player_char(map->matrix[i][map->width - 1]))
			return (-1);
		i++;
	}
	return (0);
}

int	map_check(t_cub *cub)
{
	int		pos_x;
	int		pos_y;
	int		error;
	char	**copy_map;

	if (!find_player(&cub->map, &pos_x, &pos_y))
		exit_error("Player not found");
	if (check_map_borders(&cub->map) != 0)
		exit_error("Map has open borders");
	copy_map = dup_map(cub->map.matrix, cub->map.height);
	if (!copy_map)
		exit_error("Copy map to check failed");
	if (is_player_char(cub->map.matrix[pos_y][pos_x]))
		cub->map.matrix[pos_y][pos_x] = '0';
	error = 0;
	//flood_fill(copy_map, cub->map.height, cub->map.width, pos_x, pos_y, &error);
	//free_map(copy_map, cub->map.height);
	if (error)
		exit_error("Map is not closed");
	return (0);
}
