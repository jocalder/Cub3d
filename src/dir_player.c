/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:21:54 by marvin            #+#    #+#             */
/*   Updated: 2025/12/11 17:21:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	int pixel;

	pixel = 0;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = (y * img->line_len) + (x * (img->bpp / 8));
	*(int *)(img->addr + pixel) = color;
}

int	render_frame(t_cub *cub)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(&cub->mlx.img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	if (cub->keys.w)
	cub->player.pos_y -= 2;
	if (cub->keys.s)
	cub->player.pos_y += 2;
	if (cub->keys.a)
	cub->player.pos_x -= 2;
	if (cub->keys.d)
	cub->player.pos_x += 2;
	//put_pixel(&cub->mlx.img, (int)cub->player.pos_x, (int)cub->player.pos_y, 0xFF0000);
	int i, j;
	int pixel;

	i = 0;
	while (i < POINT_SIZE)
	{
    	j = 0;
    	while (j < POINT_SIZE)
    	{
        	int x = cub->player.pos_x + j;
        	int y = cub->player.pos_y + i;
        	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
        	{
            	pixel = y * cub->mlx.img.line_len + x * (cub->mlx.img.bpp / 8);
            	*(int *)(cub->mlx.img.addr + pixel) = 0x000000;
        	}
        	j++;
    	}
    	i++;
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img.ptr, 0, 0);
	return (0);
}