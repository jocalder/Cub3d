/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:03:43 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:03:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	calculate_step_x(t_cub *cub)
{
	if (cub->ray.dir_x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.sidedist_x = (cub->player.pos_x - cub->ray.map_x)
			* cub->ray.delta_x;
	}
	else
	{
		cub->ray.step_x = 1;
		cub->ray.sidedist_x = (cub->ray.map_x + 1.0 - cub->player.pos_x)
			* cub->ray.delta_x;
	}
}

static void	calculate_step_y(t_cub *cub)
{
	if (cub->ray.dir_y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.sidedist_y = (cub->player.pos_y - cub->ray.map_y)
			* cub->ray.delta_y;
	}
	else
	{
		cub->ray.step_y = 1;
		cub->ray.sidedist_y = (cub->ray.map_y + 1.0 - cub->player.pos_y)
			* cub->ray.delta_y;
	}
}

void	calculate_step(t_cub *cub)
{
	calculate_step_x(cub);
	calculate_step_y(cub);
}
