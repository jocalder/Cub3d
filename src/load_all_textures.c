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

int	get_texture_pixel(t_img *texture, int x, int y)
{
	char	*dest;

	dest = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dest);
}
