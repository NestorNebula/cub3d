/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:48:05 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:18:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void	move_top(t_data *data, t_map *map, double speed);

static void	move_down(t_data *data, t_map *map, double speed);

static void	move_left(t_data *data, t_map *map, double speed);

static void	move_right(t_data *data, t_map *map, double speed);

void	move(int moveflag, t_data *data)
{
	double	move_speed;

	move_speed = data->frame_time * 5.0;
	if (moveflag & M_UP)
		move_top(data, &data->scene->map, move_speed);
	if (moveflag & M_DOWN)
		move_down(data, &data->scene->map, move_speed);
	if (moveflag & M_LEFT)
		move_left(data, &data->scene->map, move_speed);
	if (moveflag & M_RIGHT)
		move_right(data, &data->scene->map, move_speed);
}

static void	move_top(t_data *data, t_map *map, double speed)
{
	if (is_walkable(map, data->player.pos_x + data->player.dir_x * speed,
			data->player.pos_y))
		data->player.pos_x += data->player.dir_x * speed;
	if (is_walkable(map, data->player.pos_x,
			data->player.pos_y + data->player.dir_y * speed))
		data->player.pos_y += data->player.dir_y * speed;
}

static void	move_down(t_data *data, t_map *map, double speed)
{
	if (is_walkable(map, data->player.pos_x - data->player.dir_x * speed,
			data->player.pos_y))
		data->player.pos_x -= data->player.dir_x * speed;
	if (is_walkable(map, data->player.pos_x,
			data->player.pos_y - data->player.dir_y * speed))
		data->player.pos_y -= data->player.dir_y * speed;
}

static void	move_left(t_data *data, t_map *map, double speed)
{
	map = &data->scene->map;
	if (is_walkable(map, data->player.pos_x - data->player.plane_x * speed,
			data->player.pos_y))
		data->player.pos_x -= data->player.plane_x * speed;
	if (is_walkable(map, data->player.pos_x,
			data->player.pos_y - data->player.plane_y * speed))
		data->player.pos_y -= data->player.plane_y * speed;
}

static void	move_right(t_data *data, t_map *map, double speed)
{
	if (is_walkable(map, data->player.pos_x + data->player.plane_x * speed,
			data->player.pos_y))
		data->player.pos_x += data->player.plane_x * speed;
	if (is_walkable(map, data->player.pos_x,
			data->player.pos_y + data->player.plane_y * speed))
		data->player.pos_y += data->player.plane_y * speed;
}
