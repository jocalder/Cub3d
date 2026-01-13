/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 14:21:53 by vgoyzuet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/13 17:30:02 by vgoyzuet         ###   ########.fr       */
=======
/*   Updated: 2026/01/13 17:41:46 by vgoyzuet         ###   ########.fr       */
>>>>>>> ae679a6620aa19d9cb97fde2ac8f17d697cc7140
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	is_spacetab(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	**dup_map(char **src, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		exit_error("Malloc copy map failed");
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy)
			break ;
		i++;
	}
	if (i < height)
	{
		while (--i > 0)
			free(copy[i - 1]);
		free(copy);
		return (NULL);
	}
	copy[height] = NULL;
	return (copy);
}

int	validate_characters(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!is_player_char(map->matrix[y][x])
				&& !is_spacetab(map->matrix[y][x])
				&& map->matrix[y][x] != '0' && map->matrix[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
