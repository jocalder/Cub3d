/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:05:11 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:05:11 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	padding_rows(t_map *map)
{
	int		y;
	int		len;
	char	*row;

	y = 0;
	while (y < map->height)
	{
		len = ft_strlen(map->matrix[y]);
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

static int	check_side_width(char **map, int i, int side)
{
	if (!map)
		return (-1);
	if (map[0][i] == '0' || is_player_char(map[0][i]))
		return (-1);
	if (is_spacetab(map[0][i])
		&& (side > 1 && map[1][i] == '0'
		|| is_player_char(map[1][i])))
		return (-1);
	if (map[side - 1][i] == '0'
		|| is_player_char(map[side - 1][i]))
		return (-1);
	if (is_spacetab(map[side - 1][i])
		&& (side > 1 && map[side - 2][i] == '0'
		|| is_player_char(map[side - 2][i])))
		return (-1);
	return (0);
}

static int	check_side_height(char **map, int i, int side)
{
	if (!map)
		return (-1);
	if (map[i][0] == '0' || is_player_char(map[i][0]))
		return (-1);
	if (is_spacetab(map[i][0])
		&& (side > 1 && (map[i][1] == '0'
		|| is_player_char(map[i][1]))))
		return (-1);
	if (map[i][side - 1] == '0'
		|| is_player_char(map[i][side - 1]))
		return (-1);
	if (is_spacetab(map[i][side - 1])
		&& (side > 1 && map[i][side - 2] == '0'
		|| is_player_char(map[i][side - 2])))
		return (-1);
	return (0);
}

static int	check_map_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (check_side_width(map->matrix, i, map->height) != 0)
			return (-1);
		i++;
	}
	i = 0;
	while (i > map->height)
	{
		if (check_side_height(map->matrix, i, map->width) != 0)
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

	if (validate_characters(&cub->map) != 1)
		exit_error("Invalid characters");
	if (validate_player(&cub->map, &pos_x, &pos_y) != 1)
		exit_error("Invalid player");
	if (check_map_borders(&cub->map) != 0)
		exit_error("Map has open borders");
	cub->map.cpy_map = dup_map(cub->map.matrix, cub->map.height);
	if (!cub->map.cpy_map)
		exit_error("Copy map to check failed");
	error = 0;
	flood_fill(cub->map, pos_y, pos_x, &error);
	free_map(cub->map.cpy_map, cub->map.height);
	if (error)
		exit_error("Map is not closed");
	return (0);
}
