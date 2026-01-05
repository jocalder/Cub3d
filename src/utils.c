/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:52:12 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 11:52:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	exit_error(const char *str)
{
	if (str)
		write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	free_map(char **map, int height)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (i < height && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*get_path(char *line)
{
	char	*path;

	path = ft_strtrim(line, "\n\t");
	if (!path || *path == '\0')
		exit_error("Invalid texture path");
	if (access(path, F_OK) != 0)
		exit_error("Texture file not found");
	return (path);
}
