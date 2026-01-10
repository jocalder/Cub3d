/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:26 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	**parse_map(char **lines, int start, int *out_height, int *out_width)
{
	char	**map;
	int		i;
	int		height;
	int		width;

	i = start - 1;
	height = 0;
	if (!lines)
		return (NULL);
	while (lines[++i])
		height++;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map)
		exit_error("Malloc\n");
	i = start - 1;
	height = 0;
	width = 0;
	while (lines[++i])
	{
		map[height] = cpy_map(ft_strdup(lines[i]), &width);
		height++;
	}
	*out_height = height;
	*out_width = width;
	return (map);
}

static int	parse_lines_identifier(t_map *map, char *line)
{
	if (!line)
		return (0);
	if (parse_texture_north_and_south(map, line))
		return (1);
	if (parse_texture_west_and_east(map, line))
		return (1);
	if (parse_floor_and_ceiling(map, line))
		return (1);
	return (0);
}

static int	find_map_start(t_map *map, char	**lines)
{
	int		i;
	int		j;

	if (!lines)
		return (-1);
	i = 0;
	while (lines[i])
	{
		if (parse_lines_identifier(map, lines[i]) == 1)
		{
			i++;
			continue ;
		}
		j = 0;
		while (is_spacetab(lines[i][j]))
			j++;
		if (lines[i][j] == '1' || lines[i][j] == '0')
			return (i);
		i++;
	}
	return (-1);
}

static char	**read_lines(int fd)
{
	char	**array;
	char	*line;
	int		count;

	array = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		array = add_line(array, line, count);
		count++;
		line = get_next_line(fd);
	}
	return (array);
}

int	parse_cub(t_cub *cub, char *path)
{
	char	**lines;
	int		fd;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Open fd");
	lines = read_lines(fd);
	if (close(fd) != 0)
		exit_error("Close fd");
	cub->map.start = find_map_start(&cub->map, lines);
	if (cub->map.start == -1)
		exit_error("Map not found");
	cub->map.matrix = parse_map(lines, cub->map.start, &cub->map.height,
			&cub->map.width);
	i = 0;
	while (lines[i])
		free(lines[i++]);
	free(lines);
	validate_identifiers(&cub->map);
	padding_rows(&cub->map);
	map_check(cub);
	init_player(cub, &cub->map);
	return (0);
}
