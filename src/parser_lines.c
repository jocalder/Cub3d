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
	r = ft_atoi(str);
	while (*str != ',' && *str != '\0')
		str++;
	if (*str != ',')
		return (-1);
	str++;
	g = ft_atoi(str);
	while (*str != ',' && *str != '\0')
		str++;
	if (*str != ',')
		return (-1);
	str++;
	b = ft_atoi(str);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
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

static char	**add_last_line(char **array, char *line, int *count)
{
	if (line)
	{
		array = add_line(array, line, *count);
		(*count)++;
	}
	return (array);
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
	array = add_last_line(array, line, &count);
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
