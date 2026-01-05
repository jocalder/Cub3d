/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 08:31:30 by marvin            #+#    #+#             */
/*   Updated: 2025/12/22 08:31:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	put_pixel(t_cub *cub, int x, int y, int color)
{
    char	*dst;

	if (x < 0 || y < 0 || x >= cub->win.width || y >= cub->win.height)
		return ;
	dst = cub->mlx.img.addr
		+ (y * cub->mlx.img.line_len + (x * cub->mlx.img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_wall_color(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.dir_x > 0)
		return (TEX_WEST);
	if (cub->ray.side == 0)
		return (TEX_EAST);
	if (cub->ray.dir_y > 0)
		return (TEX_NORTH);
	return (TEX_SOUTH);
}

void	draw_column(t_cub *cub, int x)
{
	int		y;
    int		color;

	y = 0;
	while (y < cub->ray.draw_start)
		put_pixel(cub, x, y++, cub->map.ceiling_color);
	color = get_wall_color(cub);
	while (y <= cub->ray.draw_end)
		put_pixel(cub, x, y++, color);
	while (y < cub->win.height)
		put_pixel(cub, x, y++, cub->map.floor_color);
}

void	calculate_wall(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->ray.wall_dist =
			(cub->ray.map_x - cub->player.pos_x
			+ (1 - cub->ray.step_x) / 2) / cub->ray.dir_x;
	}
	else
	{
		cub->ray.wall_dist =
			(cub->ray.map_y - cub->player.pos_y
			+ (1 - cub->ray.step_y) / 2) / cub->ray.dir_y;
	}
	if (cub->ray.wall_dist < 0.00001)
		cub->ray.wall_dist = 0.00001;
	cub->ray.line_height = (int)(cub->win.height / cub->ray.wall_dist);
	cub->ray.draw_start = -cub->ray.line_height / 2
		+ cub->win.height / 2;
	cub->ray.draw_end = cub->ray.line_height / 2
		+ cub->win.height / 2;
	if (cub->ray.draw_start < 0)
		cub->ray.draw_start = 0;
	if (cub->ray.draw_end >= cub->win.height)
		cub->ray.draw_end = cub->win.height - 1;
}
