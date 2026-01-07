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

static int	handle_close(t_cub *cub)
{
	close_program(cub);
	return (0);
}

static void	init_data(t_cub *cub)
{
	ft_bzero(cub, sizeof(t_cub));
	init_map(&cub->map);
	init_data_player(&cub->player);
	init_raycasting(&cub->ray);
	init_window(&cub->win);
	init_keys(&cub->keys);
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
