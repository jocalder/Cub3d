/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 06:06:52 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 06:06:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**parse_map(char **lines, int start, int *out_height, int *out_width)
{
	char	**map;
	int		i;
	int		height;
	int		width;

	i = start;
	height = 0;
	if (!lines)
		return (NULL);
	while (lines[i])
	{
		i++;
		height++;
	}
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit_error("Malloc error\n");
	i = start;
	height = 0;
	width = 0;
	while (lines[i])
	{
		map[height] = ft_strdup(lines[i]);
		if ((int)ft_strlen(map[height]) > width)
			width = (int)ft_strlen(map[height]);
		height++;
		i++;
	}
	*out_height = height;
	*out_width = width;
	return (map);
}

int	find_map_start(t_map *map, char	**lines)
{
	int		i;

	i = 0;
	while (lines[i])
	{
		if (parse_lines_identifier(map, lines[i]) == 1)
			;
		else if (lines[i][0] == ' ' || lines[i][0] == '1' || lines[i][0] == '0' || is_player_char(lines[i][0]))
			return (i);
		i++;
	}
	return (-1);
}

void	validate_identifiers(t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea)
		exit_error("No textures");
	if (map->floor_color == -1 || map->ceiling_color == -1)
		exit_error("No colors");
}

int	parse_cub(t_cub *cub, char *path)
{
	char	**lines;

	lines = open_and_read_lines(path);
	cub->map.start = find_map_start(&cub->map, lines);
	if (cub->map.start == -1)
		exit_error("Map not found");
	cub->map.matrix = parse_map(lines, cub->map.start, &cub->map.height, &cub->map.width);
	validate_identifiers(&cub->map);
	padding_rows(&cub->map);
	map_check(cub);
	print_map(&cub->map);
	//free_map(lines, ft_array_len(lines));
	return (0);
}


