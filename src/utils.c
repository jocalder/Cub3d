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

	path = ft_strtrim(line, " \n\t\r");
	if (!path || *path == '\0')
		exit_error("Invalid texture path");
	if (access(path, R_OK) != 0)
		exit_error("Texture file not found");
	return (path);
}

void	put_pixel(t_cub *cub, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->win.width || y >= cub->win.height)
		return ;
	dst = cub->mlx.img.addr
		+ (y * cub->mlx.img.line_len + (x * cub->mlx.img.bpp / 8));
	*(unsigned int *)dst = color;
}
