/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:48:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 13:48:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	*skip_spaces(char *str)
{
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	return (str);
}

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
	if (ft_strncmp(line, "NO", 3) == 0 && !map->no)
		map->no = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO", 3) == 0 && !map->so)
		map->so = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE", 3) == 0 && !map->we)
		map->we = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA", 3) == 0 && !map->ea)
		map->ea = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 3) == 0 && map->floor_color == -1)
		map->floor_color = parse_color(line + 2);
	else if (ft_strncmp(line, "C ", 3) == 0 && map->ceiling_color == -1)
		map->ceiling_color = parse_color(line + 2);
	else
		return (0);
	return (1);
}

char	**add_line(char **array, char *line, int count)
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

char	**add_last_line(char **array, char *line, int *count)
{
	if (line)
	{
		array = add_line(array, line, *count);
		(*count)++;
	}
	return (array);
}

char **read_all_lines(int fd)
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
