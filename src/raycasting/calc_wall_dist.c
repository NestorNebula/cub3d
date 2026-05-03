/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_wall_dist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <cmonmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 01:59:50 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/03 15:16:45 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calc_wall_dist(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->perp_wall_dist = (ray->map_x - data->player.pos_x
				+ (1 - ray->step_x) / 2.0) / ray->ray_dir_x;
	}
	else
	{
		ray->perp_wall_dist = (ray->map_y - data->player.pos_y
				+ (1 - ray->step_y) / 2.0) / ray->ray_dir_y;
	}
}
