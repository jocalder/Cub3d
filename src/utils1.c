/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 06:21:01 by marvin            #+#    #+#             */
/*   Updated: 2025/12/12 06:21:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	*skip_spaces(char *str)
{
	while (*str && (*str == 9 || *str == 32))
		str++;
	return (str);
}

void	print_map(t_map *map)
{
	int		i = 0;

	printf("\n--- MAP (%dx%d) ---\n", map->width, map->height);
	while (i < map->height)
	{
    	printf("%s\n", map->matrix[i]);
    	i++;
	}
	printf("\n");
}