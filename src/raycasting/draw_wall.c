/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <cmonmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:14:22 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/03 15:19:34 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "window.h"
#include "utils.h"

static void	get_draw_limits(t_data *data, t_ray *ray, t_draw *draw)
{
	draw->height = (int)(data->screen_height / ray->perp_wall_dist);
	draw->start = -draw->height / 2 + data->screen_height / 2;
	if (draw->start < 0)
		draw->start = 0;
	draw->end = draw->height / 2 + data->screen_height / 2;
	if (draw->end >= data->screen_height)
		draw->end = data->screen_height - 1;
}

static double	get_wall_x(t_data *data, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = data->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = data->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	return (1.0 - (wall_x - floor(wall_x)));
}

static void	draw_texture_column(t_data *data,
	t_ray *ray, t_texture *tex, t_draw *draw)
{
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		y;

	tex_x = (int)(get_wall_x(data, ray) * tex->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	step = 1.0 * tex->height / draw->height;
	tex_pos = (draw->start - (double) data->screen_height / 2
			+ (double) draw->height / 2) * step;
	y = draw->start;
	while (y <= draw->end)
	{
		tex_y = (int)tex_pos % tex->height;
		tex_pos += step;
		my_mlx_pixel_put(data, draw->x, y,
			shade_wall(get_texture_color(tex, tex_x, tex_y), ray));
		y++;
	}
	draw_floor_ceiling(data, draw, ray);
}

void	draw_wall_with_texture(t_data *data, t_ray *ray, int x)
{
	t_draw		draw;
	t_texture	*tex;

	draw.x = x;
	get_draw_limits(data, ray, &draw);
	tex = get_texture(data, ray);
	draw_texture_column(data, ray, tex, &draw);
}
