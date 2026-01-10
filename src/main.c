/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:57:23 by vgoyzuet          #+#    #+#             */
/*   Updated: 2026/01/07 18:57:23 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static void	init_data(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	init_map(&cub->map);
	init_data_player(&cub->player);
	init_raycasting(&cub->ray);
	init_window(&cub->win);
	init_keys(&cub->keys);
}

static void	load_texture(t_cub *cub, t_img *texture, char *path)
{
	texture->ptr = mlx_xpm_file_to_image(cub->mlx.mlx,
			path, &texture->width, &texture->height);
	if (!texture->ptr)
		exit_error("Error loading texture");
	texture->addr = mlx_get_data_addr(texture->ptr,
			&texture->bpp, &texture->line_len, &texture->endian);
}

static void	load_all_textures(t_cub *cub)
{
	if (!cub->map.no || !cub->map.so || !cub->map.we
		|| !cub->map.ea)
		exit_error("Missing textures path");
	load_texture(cub, &cub->textures[TEX_NORTH], cub->map.no);
	load_texture(cub, &cub->textures[TEX_SOUTH], cub->map.so);
	load_texture(cub, &cub->textures[TEX_WEST], cub->map.we);
	load_texture(cub, &cub->textures[TEX_EAST], cub->map.ea);
}

static void	init_mlx(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (cub->mlx.mlx == NULL)
		exit_error("mlx_init failed\n");
	load_all_textures(cub);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (cub->mlx.win == NULL)
		exit_error("mlx_init_window failed\n");
	cub->mlx.img.ptr = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	if (cub->mlx.img.ptr == NULL)
		exit_error("mlx_new_image failed\n");
	cub->mlx.img.addr = mlx_get_data_addr(cub->mlx.img.ptr,
			&cub->mlx.img.bpp, &cub->mlx.img.line_len, &cub->mlx.img.endian);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		exit_error("Usage: ./cub3d <map.cub>");
	init_data(&cub);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		exit_error("Please use a valid map");
	if (parse_cub(&cub, argv[1]) != 0)
		exit_error("Please use a valid map");
	init_mlx(&cub);
	mlx_clear_window(cub.mlx.mlx, cub.mlx.win);
	mlx_loop_hook(cub.mlx.mlx, render_frame, &cub);
	mlx_hook(cub.mlx.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.mlx.win, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.mlx.win, 17, 0, handle_close, &cub);
	mlx_loop(cub.mlx.mlx);
	return (0);
}
