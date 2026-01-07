/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_readlines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:48:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/10 13:48:56 by marvin           ###   ########.fr       */
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
	free(array);
	return (new_array);
}

char **read_lines(int fd)
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
