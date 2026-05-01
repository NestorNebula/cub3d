/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:39:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/30 10:19:10 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "core.h"

static int	loop(t_data *data);

static int	on_key_press_event(int keycode, t_data *data);

static int	on_key_release_event(int keycode, t_data *data);

static int	on_close_event(t_data *data);

void		handle_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, (void *) on_key_press_event, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, (void *) on_key_release_event, data);
	mlx_hook(data->win, DestroyNotify, NoEventMask, (void *) on_close_event, data);
	mlx_loop_hook(data->mlx, (void *) loop, data);
	mlx_loop(data->mlx);
}

static int	loop(t_data *data)
{
	void	*prev_img;
	double	now;

	prev_img = data->img.img;
	data->img.img = mlx_new_image(data->mlx,
		data->screen_width, data->screen_height);
	if (data->img.img != NULL)
	{
		data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
		draw(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	if (prev_img != NULL)
		mlx_destroy_image(data->mlx, prev_img);
	now = get_time();
	data->frame_time = (now - data->old_time);
	data->old_time = now;
	return (0);
}

static int	on_key_press_event(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		on_close_event(data);
	else if (keycode == XK_w)
		data->player.moveflag |= D_UP;
	else if (keycode == XK_s)
		data->player.moveflag |= D_DOWN;
	else if (keycode == XK_a)
		data->player.moveflag |= D_LEFT;
	else if (keycode == XK_d)
		data->player.moveflag |= D_RIGHT;
	else if (keycode == XK_Left)
		data->player.moveflag |= D_LEFTL;
	else if (keycode == XK_Right)
		data->player.moveflag |= D_RIGHTL;
	return (0);
}

static int	on_key_release_event(int keycode, t_data *data)
{
	if (keycode == XK_w)
		data->player.moveflag &= ~D_UP;
	else if (keycode == XK_s)
		data->player.moveflag &= ~D_DOWN;
	else if (keycode == XK_a)
		data->player.moveflag &= ~D_LEFT;
	else if (keycode == XK_d)
		data->player.moveflag &= ~D_RIGHT;
	else if (keycode == XK_Left)
		data->player.moveflag &= ~D_LEFTL;
	else if (keycode == XK_Right)
		data->player.moveflag &= ~D_RIGHTL;
	return (0);
}

static int	on_close_event(t_data *data)
{
	mlx_loop_end(data->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}
