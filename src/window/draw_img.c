/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:47:47 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/29 11:04:04 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void		draw(t_data *data)
{
	t_ray	ray;
	int		x;

	if (data == NULL)
		return ;
	x = 0;
	draw_floor_ceiling(data);
	while (x < data->screen_width)
	{
		init_ray(data, &ray, x);
		calc_step_and_side_dist(data, &ray);
		dda(data, &ray);
		calc_wall_dist(data, &ray);
		draw_wall_with_texture(data, &ray, x);
		x++;
	}
}
