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

static void	move_left(int lookflag, t_data *data, t_map *map, double speed);

static void move_right(int lookflag, t_data *data, t_map *map, double speed);

void		move(t_dir dir, int lookflag, t_data *data)
{
	double	speed;

	if (lookflag)
		speed = data->frame_time * 5.0;
	else
		speed = data->frame_time * 3.0;
	if (dir == D_UP)
		move_top(data, &data->scene->map, speed);
	else if (dir == D_DOWN)
		move_down(data, &data->scene->map, speed);
	else if (dir == D_LEFT || dir == D_LEFTL)
		move_left(lookflag, data, &data->scene->map, speed);
	else if (dir == D_RIGHT || dir == D_RIGHTL)
		move_right(lookflag, data, &data->scene->map, speed);
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

static void	move_left(int lookflag, t_data *data, t_map *map, double speed)
{
	const t_player old_player = data->player;

	if (lookflag)
	{
		data->player.dir_x = data->player.dir_x * cos(-speed)
			- data->player.dir_y * sin(-speed);
		data->player.dir_y = old_player.dir_x * sin(-speed)
			+ data->player.dir_y * cos(-speed);
		data->player.plane_x = data->player.plane_x * cos(-speed)
			- data->player.plane_y * sin(-speed);
		data->player.plane_y = old_player.plane_x * sin(-speed)
			+ data->player.plane_y * cos(-speed);
	}
	else
	{
		if (is_walkable(map, data->player.pos_x - data->player.plane_x * speed, data->player.pos_y))
			data->player.pos_x -= data->player.plane_x * speed;
		if (is_walkable(map, data->player.pos_x, data->player.pos_y - data->player.plane_y * speed))
			data->player.pos_y -= data->player.plane_y * speed;
	}
}

static void move_right(int lookflag, t_data *data, t_map *map, double speed)
{
	const t_player old_player = data->player;

	if (lookflag)
	{
		data->player.dir_x = data->player.dir_x * cos(speed)
			- data->player.dir_y * sin(speed);
		data->player.dir_y = old_player.dir_x * sin(speed)
			+ data->player.dir_y * cos(speed);
		data->player.plane_x = data->player.plane_x * cos(speed)
			- data->player.plane_y * sin(speed);
		data->player.plane_y = old_player.plane_x * sin(speed)
			+ data->player.plane_y * cos(speed);
	}
	else
	{
		if (is_walkable(map, data->player.pos_x + data->player.plane_x * speed, data->player.pos_y))
			data->player.pos_x += data->player.plane_x * speed;
		if (is_walkable(map, data->player.pos_x, data->player.pos_y + data->player.plane_y * speed))
			data->player.pos_y += data->player.plane_y * speed;
	}
}
