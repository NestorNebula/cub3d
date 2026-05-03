/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:10:15 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:18:44 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*pixel;
	t_texture	*img;

	img = &data->img;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
