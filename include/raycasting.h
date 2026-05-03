/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <cmonmire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:34:44 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/03 15:16:10 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "data.h"

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_draw
{
	int	start;
	int	end;
	int	height;
	int	x;
}	t_draw;

void		init_ray(t_data *data, t_ray *ray, int x);
void		calc_step_and_side_dist(t_data *data, t_ray *ray);
void		calc_wall_dist(t_data *data, t_ray *ray);
void		dda(t_data *data, t_ray *ray);
void		draw_floor_ceiling(t_data *data, t_draw *draw, t_ray *ray);
void		draw_wall_with_texture(t_data *data, t_ray *ray, int x);
int			get_texture_color(t_texture *tex, int x, int y);
t_texture	*get_texture(t_data *data, t_ray *ray);

#endif
