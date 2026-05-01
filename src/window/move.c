/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:48:05 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/30 10:24:18 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "scene.h"

static void	move_top(t_data *data, t_map *map, double speed);

static void move_down(t_data *data, t_map *map, double speed);

static void	move_left(int moveflag, t_data *data, double mspeed, double rspeed);

static void move_right(int moveflag, t_data *data, double mspeed, double rspeed);

void		move(int moveflag, t_data *data)
{
	double	move_speed;
	double	rot_speed;

	move_speed = data->frame_time * 5.0;
	rot_speed = data->frame_time * 3.0;
	if (moveflag & D_UP)
		move_top(data, &data->scene->map, move_speed);
	if (moveflag & D_DOWN)
		move_down(data, &data->scene->map, move_speed);
	if ((moveflag & D_LEFT) || (moveflag & D_LEFTL))
		move_left(moveflag, data, move_speed, rot_speed);
	if ((moveflag & D_RIGHT) || (moveflag & D_RIGHTL))
		move_right(moveflag, data, move_speed, rot_speed);
}

static void	move_top(t_data *data, t_map *map, double speed)
{
	
	if (is_walkable(map, data->player.pos_x + data->player.dir_x * speed, data->player.pos_y))
		data->player.pos_x += data->player.dir_x * speed;
	if (is_walkable(map, data->player.pos_x, data->player.pos_y + data->player.dir_y * speed))
		data->player.pos_y += data->player.dir_y * speed;
}

static void move_down(t_data *data, t_map *map, double speed)
{
	if (is_walkable(map, data->player.pos_x - data->player.dir_x * speed, data->player.pos_y))
		data->player.pos_x -= data->player.dir_x * speed;
	if (is_walkable(map, data->player.pos_x, data->player.pos_y - data->player.dir_y * speed))
		data->player.pos_y -= data->player.dir_y * speed;
}

static void	move_left(int moveflag, t_data *data, double mspeed, double rspeed)
{
	const t_player	old_player = data->player;
	t_map			*map;

	if (moveflag & D_LEFTL)
	{
		data->player.dir_x = data->player.dir_x * cos(-rspeed)
			- data->player.dir_y * sin(-rspeed);
		data->player.dir_y = old_player.dir_x * sin(-rspeed)
			+ data->player.dir_y * cos(-rspeed);
		data->player.plane_x = data->player.plane_x * cos(-rspeed)
			- data->player.plane_y * sin(-rspeed);
		data->player.plane_y = old_player.plane_x * sin(-rspeed)
			+ data->player.plane_y * cos(-rspeed);
	}
	map = &data->scene->map;
	if (moveflag & D_LEFT)
	{
		if (is_walkable(map, data->player.pos_x - data->player.plane_x * mspeed, data->player.pos_y))
			data->player.pos_x -= data->player.plane_x * mspeed;
		if (is_walkable(map, data->player.pos_x, data->player.pos_y - data->player.plane_y * mspeed))
			data->player.pos_y -= data->player.plane_y * mspeed;
	}
}

static void move_right(int moveflag, t_data *data, double mspeed, double rspeed)
{
	const t_player	old_player = data->player;
	t_map			*map;

	if (moveflag & D_RIGHTL)
	{
		data->player.dir_x = data->player.dir_x * cos(rspeed)
			- data->player.dir_y * sin(rspeed);
		data->player.dir_y = old_player.dir_x * sin(rspeed)
			+ data->player.dir_y * cos(rspeed);
		data->player.plane_x = data->player.plane_x * cos(rspeed)
			- data->player.plane_y * sin(rspeed);
		data->player.plane_y = old_player.plane_x * sin(rspeed)
			+ data->player.plane_y * cos(rspeed);
	}
	map = &data->scene->map;
	if (moveflag & D_RIGHT)
	{
		if (is_walkable(map, data->player.pos_x + data->player.plane_x * mspeed, data->player.pos_y))
			data->player.pos_x += data->player.plane_x * mspeed;
		if (is_walkable(map, data->player.pos_x, data->player.pos_y + data->player.plane_y * mspeed))
			data->player.pos_y += data->player.plane_y * mspeed;
	}
}
