/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:30:07 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 12:30:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	close_program(t_cub *cub)
{
	if (cub->mlx.img.ptr)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img.ptr);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	free_map(cub->map.matrix, cub->map.height);
	exit(0);
}

int	key_press(int k, t_cub *cub)
{
	if (k == W)
		cub->keys.w = 1;
	if (k == A)
		cub->keys.a = 1;
	if (k == S)
		cub->keys.s = 1;
	if (k == D)
		cub->keys.d = 1;
	if (k == UP)
		cub->keys.up = 1;
	if (k == DOWN)
		cub->keys.down = 1;
	if (k == LEFT)
		cub->keys.left = 1;
	if (k == RIGHT)
		cub->keys.right = 1;
	if (k == ESC)
		close_program(cub);
	return (0);
}

int	key_release(int k, t_cub *cub)
{
	if (k == W)
		cub->keys.w = 0;
	if (k == A)
		cub->keys.a = 0;
	if (k == S)
		cub->keys.s = 0;
	if (k == D)
		cub->keys.d = 0;
	if (k == UP)
		cub->keys.up = 0;
	if (k == DOWN)
		cub->keys.down = 0;
	if (k == LEFT)
		cub->keys.left = 0;
	if (k == RIGHT)
		cub->keys.right = 0;
	return (0);
}
