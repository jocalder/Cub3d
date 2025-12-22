/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:44:38 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 15:44:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
}

static void	init_map(t_map *map)
{
	map->matrix = NULL;
	map->fd = 0;
	map->line_count = 0;
	map->start = -1;
	map->width = 0;
	map->height = 0;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
}

static void	init_data_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

static void	init_raycasting(t_ray *ray)
{
	ray->camera_x = 0.0;
	ray->dir_x = 0.0;
	ray->dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->delta_x = 0.0;
	ray->delta_y = 0.0;
	ray->wall_dist = 0.0;
	ray->wall_x = 0.0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

static void	init_window(t_win *window)
{
	window->width = WIDTH;
	window->height = HEIGHT;
}

void	init_data(t_cub *cub)
{
	init_map(&cub->map);
	init_data_player(&cub->player);
	init_raycasting(&cub->ray);
	init_window(&cub->win);
	init_keys(&cub->keys);
}
