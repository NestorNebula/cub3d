/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nestornebula.dev@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:08:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/28 16:08:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "core.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

static void	init_player(t_data *data);

static int	init_texture(t_stexture *scene_texture, t_texture *texture);

t_data		*init_data(t_data *data, t_scene *scene, int screen_dim[2])
{
	data->mlx = mlx_init();
	if (data->mlx != NULL)
		data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cub3D");
	if (data == NULL || scene == NULL || data->mlx == NULL
		|| data->win == NULL)
		return (NULL);
	data->screen_width = SCREEN_WIDTH;
	data->screen_height = SCREEN_HEIGHT;
	data->scene = scene;
	init_player(data);
	if (init_texture(&scene->textures.no, &data->north) == 0
			|| init_texture(&scene->textures.so, &data->south) == 0
			|| init_texture(&scene->textures.we, &data->west) == 0
			|| init_texture(&scene->textures.ea, &data->east) == 0)
		return (NULL);
	data->ceiling_color = scene->textures.c;
	data->floor_color = scene->textures.f;
	data->img.img = NULL;
	return (data);
}
