/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:14:43 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 11:14:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	close_window(t_cub *cub)
{
	(void)cub;
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
    t_cub	cubed;

	if (argc != 2)
		exit_error("Usage: ./Cub3d <valid_map.cub>");
	ft_bzero(&cubed, sizeof(t_cub));
	if (parse_cub(&cubed, argv[1]) != 0)
		exit_error("Error: Please use a valid map");
	init_data(&cubed);
	init_mlx(&cubed);
	mlx_clear_window(cubed.mlx.mlx, cubed.mlx.win);
	mlx_hook(cubed.mlx.win, 2, 1L<<0, key_press, &cubed);
	mlx_hook(cubed.mlx.win, 3, 1L<<1, key_release, &cubed);
	mlx_loop_hook(cubed.mlx.mlx, render_frame, &cubed);
	mlx_hook(cubed.mlx.win, 17, 0, close_window, &cubed);
	mlx_loop(cubed.mlx.mlx);
	return (0);
}
