/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:43 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:43 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	calculate_delta(t_cub *cub)
{
	if (cub->ray.dir_x == 0)
		cub->ray.delta_x = 1e30;
	else
		cub->ray.delta_x = fabs(1 / cub->ray.dir_x);
	if (cub->ray.dir_y == 0)
		cub->ray.delta_y = 1e30;
	else
		cub->ray.delta_y = fabs(1 / cub->ray.dir_y);
}

static void	init_dda(t_cub *cub)
{
	int		hit;

	hit = 0;
	while (!hit)
	{
		if (cub->ray.sidedist_x < cub->ray.sidedist_y)
		{
			cub->ray.sidedist_x += cub->ray.delta_x;
			cub->ray.map_x += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sidedist_y += cub->ray.delta_y;
			cub->ray.map_y += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->ray.map_y >= 0 && cub->ray.map_y < cub->map.height
			&& cub->ray.map_x >= 0 && cub->ray.map_x < cub->map.width
			&& cub->map.matrix[cub->ray.map_y][cub->ray.map_x] != '0')
			hit = 1;
	}
}

static void	init_ray(t_cub *cub, int x)
{
	cub->ray.camera_x = 2.0 * x / cub->win.width - 1;
	cub->ray.dir_x = cub->player.dir_x
		+ cub->player.plane_x * cub->ray.camera_x;
	cub->ray.dir_y = cub->player.dir_y
		+ cub->player.plane_y * cub->ray.camera_x;
	cub->ray.map_x = (int)cub->player.pos_x;
	cub->ray.map_y = (int)cub->player.pos_y;
	calculate_delta(cub);
	calculate_step(cub);
}

static void	raycast(t_cub *cub)
{
	int		x;

	x = 0;
	while (x < cub->win.width)
	{
		init_ray(cub, x);
		init_dda(cub);
		calculate_wall(cub);
		draw_column(cub, x);
		x++;
	}
}

int	render_frame(t_cub *cub)
{
	update_player(cub);
	raycast(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win,
		cub->mlx.img.ptr, 0, 0);
	return (0);
}
