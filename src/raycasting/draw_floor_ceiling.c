/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <cmonmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:46:47 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/02 10:20:57 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "utils.h"

void	draw_floor_ceiling(t_data *data, t_draw *draw, t_ray *ray)
{
	int	y;

	(void) ray;
	y = 0;
	while (y < draw->start)
	{
		my_mlx_pixel_put(data, draw->x, y,
			shade_ceiling(data->ceiling_color, y, data));
		y++;
	}
	y = draw->end;
	while (y < data->screen_height)
	{
		my_mlx_pixel_put(data, draw->x, y,
			shade_floor(data->floor_color, y, data));
		y++;
	}
}
