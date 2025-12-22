/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:27:46 by marvin            #+#    #+#             */
/*   Updated: 2025/12/19 12:27:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	move_axis(t_cub *cub, double x, double y)
{
	if (is_walkable(&cub->map, x, cub->player.pos_y))
		cub->player.pos_x = x;
	if (is_walkable(&cub->map, cub->player.pos_x, y))
		cub->player.pos_y = y;
}

void	move_forward(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.pos_x + cub->player.dir_x * MOVE_SPEED;
	y = cub->player.pos_y + cub->player.dir_y * MOVE_SPEED;
	move_axis(cub, x, y);
}

void	move_backward(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.pos_x - cub->player.dir_x * MOVE_SPEED;
	y = cub->player.pos_y - cub->player.dir_y * MOVE_SPEED;
	move_axis(cub, x, y);
}

void	move_left(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.pos_x - cub->player.plane_x * MOVE_SPEED;
	y = cub->player.pos_y - cub->player.plane_y * MOVE_SPEED;
	move_axis(cub, x, y);
}

void	move_right(t_cub *cub)
{
	double	x;
	double	y;

	x = cub->player.pos_x + cub->player.plane_x * MOVE_SPEED;
	y = cub->player.pos_y + cub->player.plane_y * MOVE_SPEED;
	move_axis(cub, x, y);
}