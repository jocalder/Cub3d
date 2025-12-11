/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:07:55 by marvin            #+#    #+#             */
/*   Updated: 2025/12/09 15:07:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_mlx(t_cub *cub)
{
	//int		x;
	//int		y;
	//int		pixel;

	cub->mlx.mlx = mlx_init();
	if (cub->mlx.mlx == NULL)
		exit_error("mlx_init failed\n");
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "CUB3D");
	if (cub->mlx.win == NULL)
		exit_error("mlx_init_window failed\n");
	cub->mlx.img.ptr = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	if (cub->mlx.img.ptr == NULL)
		exit_error("mlx_new_image failed\n");
	cub->mlx.img.addr = mlx_get_data_addr(cub->mlx.img.ptr,
			&cub->mlx.img.bpp, &cub->mlx.img.line_len, &cub->mlx.img.endian);
	/*y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = (y * cub->mlx.img.line_len) + (x * (cub->mlx.img.bpp / 8));
			*(int *)(cub->mlx.img.addr + pixel) = 0xFF0000;
			x++;
		}
		y++;
	}*/
}
