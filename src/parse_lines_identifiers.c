/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines_identifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:28:10 by marvin            #+#    #+#             */
/*   Updated: 2026/01/05 11:28:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	parse_color(char *str)
{
	int		r;
	int		g;
	int		b;

	if (!str)
		return (-1);
	while (*str == ' ' || *str == '\t')
		str++;
	r = parse_value(&str);
	if (r == -1 || *str != ',')
		return (-1);
	str++;
	g = parse_value(&str);
	if (g == -1 || *str != ',')
		return (-1);
	str++;
	b = parse_value(&str);
	if (b == -1)
		return (-1);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (ft_isalpha(*str))
		exit_error("Please enter a valid value to floor and ceiling color");
	return ((r << 16) | (g << 8) | b);
}

static int	parse_texture_north_and_south(t_map *map, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (map->no)
			exit_error("Duplicate NO texture");
		map->no = get_path(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (map->so)
			exit_error("Duplicate SO texture");
		map->so = get_path(line + 3);
		return (1);
	}
	return (0);
}

static int	parse_texture_west_and_east(t_map *map, char *line)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (map->we)
			exit_error("Duplicate WE texture");
		map->we = get_path(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (map->ea)
			exit_error("Duplicate EA texture");
		map->ea = get_path(line + 3);
		return (1);
	}
	return (0);
}

static int	parse_floor_and_ceiling(t_map *map, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (map->floor_color != -1)
			exit_error("Duplicate floor color");
		map->floor_color = parse_color(line + 2);
		if (map->floor_color == -1)
			exit_error("Invalid floor color");
		return (1);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (map->ceiling_color != -1)
			exit_error("Duplicate ceilin color");
		map->ceiling_color = parse_color(line + 2);
		if (map->ceiling_color == -1)
			exit_error("Invalid ceiling color");
		return (1);
	}
	return (0);
}

int	parse_lines_identifier(t_map *map, char *line)
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
