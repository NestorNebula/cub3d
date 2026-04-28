/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahoussier </var/spool/mail/noahoussier>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 15:15:17 by noahoussier       #+#    #+#             */
/*   Updated: 2026/04/28 15:25:55 by noahoussier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*pixel;
	t_texture	*img;

	img = &data->img;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
