/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:58 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:58 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	exit_error(const char *str)
{
	write(STDERR_FILENO, "Error", 6);
	if (str)
	{
		write(STDERR_FILENO, ": ", 3);
		write(STDERR_FILENO, str, ft_strlen(str));
	}
	write(STDERR_FILENO, "\n", 1);
	exit(1);
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
	if (array)
		free(array);
	return (new_array);
}

int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

char	*get_path(char *line)
{
	char	*path;

	path = ft_strtrim(line, " \n\t\r");
	if (!path || *path == '\0')
		exit_error("Invalid texture path");
	if (access(path, R_OK) != 0)
		exit_error("Texture file not found");
	return (path);
}

char	*cpy_map(char *line, int *width)
{
	char	*cpy_line;

	if (!line || !width)
		return (NULL);
	cpy_line = NULL;
	cpy_line = line;
	if ((int)ft_strlen(cpy_line) > *width)
		*width = (int)ft_strlen(cpy_line);
	return (cpy_line);
}
