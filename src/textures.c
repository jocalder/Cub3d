/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:04:54 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/08 00:04:54 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	load_texture(t_cub *cub, t_img *texture, char *path)
{
	texture->ptr = mlx_xpm_file_to_image(cub->mlx.mlx,
			path, &texture->width, &texture->height);
	if (!texture->ptr)
		exit_error("Error loading texture");
	texture->addr = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->line_len, &texture->endian);
}

void	load_all_textures(t_cub *cub)
{
	if (!cub->map.no || !cub->map.so || !cub->map.we
		|| !cub->map.ea)
		exit_error("Missing textures path");
	load_texture(cub, &cub->textures[TEX_NORTH], cub->map.no);
	load_texture(cub, &cub->textures[TEX_SOUTH], cub->map.so);
	load_texture(cub, &cub->textures[TEX_WEST], cub->map.we);
	load_texture(cub, &cub->textures[TEX_EAST], cub->map.ea);
}

int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*dest;

	dest = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dest);
}
