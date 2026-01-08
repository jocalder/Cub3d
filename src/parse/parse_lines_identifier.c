/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines_identifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:20 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:20 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	parse_value(char **str)
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

static int	parse_color(char *str)
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

int	parse_texture_north_and_south(t_map *map, char *line)
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

int	parse_texture_west_and_east(t_map *map, char *line)
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

int	parse_floor_and_ceiling(t_map *map, char *line)
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
