/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 14:58:01 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/02 10:18:38 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

static void	rotate_left(t_data *data, double speed);

static void	rotate_right(t_data *data, double speed);

void	rotate(int moveflag, t_data *data)
{
	double	rot_speed;

	rot_speed = data->frame_time * 3.0;
	if (moveflag & R_LEFT)
		rotate_left(data, rot_speed);
	if (moveflag & R_RIGHT)
		rotate_right(data, rot_speed);
}

static void	rotate_left(t_data *data, double speed)
{
	const t_player	old_player = data->player;

	data->player.dir_x = data->player.dir_x * cos(-speed)
		- data->player.dir_y * sin(-speed);
	data->player.dir_y = old_player.dir_x * sin(-speed)
		+ data->player.dir_y * cos(-speed);
	data->player.plane_x = data->player.plane_x * cos(-speed)
		- data->player.plane_y * sin(-speed);
	data->player.plane_y = old_player.plane_x * sin(-speed)
		+ data->player.plane_y * cos(-speed);
}

static void	rotate_right(t_data *data, double speed)
{
	const t_player	old_player = data->player;

	data->player.dir_x = data->player.dir_x * cos(speed)
		- data->player.dir_y * sin(speed);
	data->player.dir_y = old_player.dir_x * sin(speed)
		+ data->player.dir_y * cos(speed);
	data->player.plane_x = data->player.plane_x * cos(speed)
		- data->player.plane_y * sin(speed);
	data->player.plane_y = old_player.plane_x * sin(speed)
		+ data->player.plane_y * cos(speed);
}
