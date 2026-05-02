/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:11:39 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/02 10:24:55 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)data->screen_width - 1;
	ray->ray_dir_x = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_dir_y = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.pos_x;
	ray->map_y = (int)data->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}
