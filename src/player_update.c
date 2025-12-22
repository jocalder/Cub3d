/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:30:07 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 12:30:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	rotate_player(t_cub *cub, double rotate)
{
	double	old_dirx;
    double	old_planex;

	old_dirx = cub->player.dir_x;
	cub->player.dir_x = cub->player.dir_x * cos(rotate)
		- cub->player.dir_y * sin(rotate);
	cub->player.dir_y = old_dirx * sin(rotate)
		+ cub->player.dir_y * cos(rotate);
	old_planex = cub->player.plane_x;
	cub->player.plane_x = cub->player.plane_x * cos(rotate)
		- cub->player.plane_y * sin(rotate);
	cub->player.plane_y = old_planex * sin(rotate)
		+ cub->player.plane_y * cos(rotate);
}

void    update_player(t_cub *cub)
{
	if (cub->keys.w)
		move_forward(cub);
	if (cub->keys.s)
		move_backward(cub);
	if (cub->keys.a)
		move_left(cub);
	if (cub->keys.d)
		move_right(cub);
	if (cub->keys.up)
		move_forward(cub);
	if (cub->keys.down)
		move_backward(cub);
	if (cub->keys.left)
		rotate_player(cub, -ROT_SPEED);
	if (cub->keys.right)
		rotate_player(cub, ROT_SPEED);
}
