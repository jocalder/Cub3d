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
		write(2, &str, ft_strlen(str));
	write(2, "\n", 1);
	exit(1);
}

/*int	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}*/

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

/*int	ft_array_len(char **array)
{
	int		i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

int	is_bad_char(char c)
{
	if (c == ' ')
		return (1);
	return (0);
}*/
