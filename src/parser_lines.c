/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:48:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 13:48:56 by marvin           ###   ########.fr       */
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
		exit_error("Please enter a valid value to floor color");
	return ((r << 16) | (g << 8) | b);
}

int	parse_lines_identifier(t_map *map, char *line)
{
	if (!line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (map && !map->no)
			map->no = ft_strdup(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (map && !map->so)
			map->so = ft_strdup(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (map && !map->we)
			map->we = ft_strdup(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (map && !map->ea)
			map->ea = ft_strdup(line + 3);
		return (1);
	}
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (map && map->floor_color == -1)
			map->floor_color = parse_color(line + 2);
		return (1);
	}
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (map && map->ceiling_color == -1)
			map->ceiling_color = parse_color(line + 2);
		return (1);
	}
	return (0);
}

static char	**add_line(char **array, char *line, int count)
{
	char	**new_array;
	int		i;

	i = 0;
	new_array = (char **)malloc(sizeof(char *) * (count + 2));
	if (!new_array)
		return (NULL);
	while (i < count)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[count] = line;
	new_array[count + 1] = NULL;
	free(array);
	return (new_array);
}

static char **read_all_lines(int fd)
{
	char	**array;
	char	*line;
	int		count;

	array = NULL;
	count = 0;
	while ((line = get_next_line(fd)))
	{
		array = add_line(array, line, count);
		count++;
	}
	return (array);
}

char	**open_and_read_lines(char *path)
{
	int		fd;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("File not ready");
	lines = read_all_lines(fd);
	close(fd);
	return (lines);
}
