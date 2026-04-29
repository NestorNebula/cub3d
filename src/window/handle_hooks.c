/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 10:39:04 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/29 11:13:05 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "core.h"

static int	loop(void);

static t_data	*access_data(void *ptr);

void		handle_hooks(t_data *data)
{
	access_data(data);
	mlx_loop_hook(data->mlx, loop, data);
	mlx_loop(data->mlx);
}

static int	loop(void)
{
	t_data	*data;
	void	*prev_img;

	data = access_data(NULL);
	while (data->win != NULL)
	{
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
		if (data->img.img == NULL)
		{
			mlx_loop_end(data->mlx);
			break ;
		}
	}
	return (0);
}

static t_data	*access_data(void *ptr)
{
	static t_data	*data = NULL;
	if (ptr != NULL)
		data = ptr;
	return (data);
}
