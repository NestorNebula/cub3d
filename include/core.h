/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:50:59 by cmonmire          #+#    #+#             */
/*   Updated: 2026/04/30 10:17:51 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <math.h>
# include <stdlib.h>
#include <X11/keysym.h>
# include <mlx.h>
# include "player.h"
# include "ray.h"
# include "scene.h"

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}	t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_texture	img;
	int			screen_width;
	int			screen_height;
	t_scene		*scene;
	t_player	player;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	int			ceiling_color;
	int			floor_color;
	double		old_time;
	double		frame_time;
}	t_data;

typedef enum e_dir {
	D_UP = XK_w,
	D_DOWN = XK_s,
	D_LEFT = XK_a,
	D_RIGHT = XK_d,
	D_LEFTL = XK_Left,
	D_RIGHTL = XK_Right,
}	t_dir;

void		init_ray(t_data *data, t_ray *ray, int x);
void		calc_step_and_side_dist(t_data *data, t_ray *ray);
void		calc_wall_dist(t_data *data, t_ray *ray);
void		dda(t_data *data, t_ray *ray);
void		draw_floor_ceiling(t_data *data);
void		draw_wall_with_texture(t_data *data, t_ray *ray, int x);
int			get_texture_color(t_texture *tex, int x, int y);
t_texture	*get_texture(t_data *data, t_ray *ray);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_data		*init_data(t_data *data, t_scene *scene);
void		handle_hooks(t_data *data);
void		draw(t_data *data);
void		move(t_dir dir, int lookflag, t_data *data);
double		get_time(void);

#endif
