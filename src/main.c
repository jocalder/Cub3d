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

static int	handle_close(t_cub *cub)
{
	close_program(cub);
	return (0);
}

int main(int argc, char **argv)
{
    t_cub	cubed;

	if (argc != 2)
		exit_error("Usage: ./Cub3d <valid_map.cub>");
	// ft_bzero(&cubed, sizeof(t_cub));
	init_data(&cubed);
	if (parse_cub(&cubed, argv[1]) != 0)
		exit_error("Error: Please use a valid map");
	init_mlx(&cubed);
	mlx_clear_window(cubed.mlx.mlx, cubed.mlx.win);
	mlx_loop_hook(cubed.mlx.mlx, render_frame, &cubed);
	mlx_hook(cubed.mlx.win, 2, 1L<<0, key_press, &cubed);
	mlx_hook(cubed.mlx.win, 3, 1L<<1, key_release, &cubed);
	mlx_hook(cubed.mlx.win, 17, 0, handle_close, &cubed);
	mlx_loop(cubed.mlx.mlx);
	return (0);
}
