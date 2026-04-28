/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <cmonmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:46:47 by cmonmire          #+#    #+#             */
/*   Updated: 2026/04/21 08:54:22 by cmonmire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void	draw_floor_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	mid;

	mid = data->screen_height / 2;
	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			if (y < mid)
				my_mlx_pixel_put(data, x, y, data->ceiling_floor);
			else
				my_mlx_pixel_put(data, x, y, data->floor_color);
			x++;
		}
		y++;
	}
}
