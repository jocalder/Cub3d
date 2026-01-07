/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:02 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:02 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	key_press(int k, t_cub *cub)
{
	if (k == W)
		cub->keys.w = 1;
	else if (k == A)
		cub->keys.a = 1;
	else if (k == S)
		cub->keys.s = 1;
	else if (k == D)
		cub->keys.d = 1;
	else if (k == UP)
		cub->keys.up = 1;
	else if (k == DOWN)
		cub->keys.down = 1;
	else if (k == LEFT)
		cub->keys.left = 1;
	else if (k == RIGHT)
		cub->keys.right = 1;
	else if (k == ESC)
		close_program(cub);
	return (0);
}

int	key_release(int k, t_cub *cub)
{
	if (k == W)
		cub->keys.w = 0;
	else if (k == A)
		cub->keys.a = 0;
	else if (k == S)
		cub->keys.s = 0;
	else if (k == D)
		cub->keys.d = 0;
	else if (k == UP)
		cub->keys.up = 0;
	else if (k == DOWN)
		cub->keys.down = 0;
	else if (k == LEFT)
		cub->keys.left = 0;
	else if (k == RIGHT)
		cub->keys.right = 0;
	return (0);
}
