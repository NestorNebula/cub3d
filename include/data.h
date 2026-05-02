/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmonmire <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 23:50:59 by cmonmire          #+#    #+#             */
/*   Updated: 2026/05/02 10:14:17 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <mlx.h>
# include "player.h"
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

t_data		*init_data(t_data *data, t_scene *scene);
void		free_data(t_data *data);

#endif
