/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:49 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:49 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	if (array)
		free(array);
	return (new_array);
}

char	**read_lines(int fd)
{
	char	**array;
	char	*line;
	int		count;

	array = NULL;
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		array = add_line(array, line, count);
		count++;
		line = get_next_line(fd);
	}
	return (array);
}
