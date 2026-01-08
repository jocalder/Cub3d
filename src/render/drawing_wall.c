/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:03:49 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:03:49 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	calculate_wall_x(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.wall_x = cub->player.pos_y
			+ cub->ray.wall_dist * cub->ray.dir_y;
	else
		cub->ray.wall_x = cub->player.pos_x
			+ cub->ray.wall_dist * cub->ray.dir_x;
	cub->ray.wall_x = cub->ray.wall_x - (int)cub->ray.wall_x;
}

static t_img	*get_wall_texture(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.dir_x > 0)
			return (&cub->textures[TEX_EAST]);
		return (&cub->textures[TEX_WEST]);
	}
	if (cub->ray.dir_y > 0)
		return (&cub->textures[TEX_SOUTH]);
	return (&cub->textures[TEX_NORTH]);
}

static void	draw_textured_column(t_cub *cub, int x)
{
	t_img	*tex;
	int		y;
	int		texture_x;
	double	step;

	tex = get_wall_texture(cub);
	calculate_wall_x(cub);
	texture_x = (int)(cub->ray.wall_x * tex->width);
	if ((cub->ray.side == 0 && cub->ray.dir_x > 0)
		|| (cub->ray.side == 1 && cub->ray.dir_y < 0))
		texture_x = tex->width - texture_x - 1;
	if (cub->ray.line_height == 0)
		return ;
	step = (double)tex->height / (double)cub->ray.line_height;
	cub->ray.tex_pos = (cub->ray.draw_start - cub->win.height / 2
			+ cub->ray.line_height / 2) * step;
	y = cub->ray.draw_start;
	while (y <= cub->ray.draw_end)
	{
		cub->ray.tex_y = (int)cub->ray.tex_pos;
		if (cub->ray.tex_y < 0)
			cub->ray.tex_y = 0;
		if (cub->ray.tex_y >= tex->height)
			cub->ray.tex_y = tex->height - 1;
		put_pixel(cub, x, y, get_texture_pixel(tex, texture_x, cub->ray.tex_y));
		cub->ray.tex_pos += step;
		y++;
	}
}

void	draw_column(t_cub *cub, int x)
{
	int		y;

	y = 0;
	while (y < cub->ray.draw_start)
		put_pixel(cub, x, y++, cub->map.ceiling_color);
	draw_textured_column(cub, x);
	y = cub->ray.draw_end + 1;
	while (y < cub->win.height)
		put_pixel(cub, x, y++, cub->map.floor_color);
}

void	calculate_wall(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		cub->ray.wall_dist = (cub->ray.map_x - cub->player.pos_x
				+ (1 - cub->ray.step_x) / 2) / cub->ray.dir_x;
	}
	else
	{
		cub->ray.wall_dist = (cub->ray.map_y - cub->player.pos_y
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
