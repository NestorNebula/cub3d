/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nestornebula.dev@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:08:57 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/30 10:15:32 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "core.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

static void	init_player(t_data *data);

static int	init_texture(t_data *data, t_stexture *scene_texture,
							t_texture *texture);

t_data		*init_data(t_data *data, t_scene *scene)
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
	if (init_texture(data, &scene->textures.no, &data->north) == 0
			|| init_texture(data, &scene->textures.so, &data->south) == 0
			|| init_texture(data, &scene->textures.we, &data->west) == 0
			|| init_texture(data, &scene->textures.ea, &data->east) == 0)
		return (NULL);
	data->ceiling_color = scene->textures.c;
	data->floor_color = scene->textures.f;
	data->img.img = NULL;
	data->old_time = get_time();
	return (data);
}

static void	init_player(t_data *data)
{
	t_square	*start;
	int			xy[2];
	
	ft_bzero(&data->player, sizeof(t_player));
	start = data->scene->map.start;
	get_square_coordinates(start, &data->scene->map, xy, xy + 1);
	data->player.pos_x = (double) xy[0] + 0.5;
	data->player.pos_y = (double) xy[1] + 0.5;
	if (start->orientation == 'N')
		data->player.dir_y = -1;
	else if (start->orientation == 'S')
		data->player.dir_y = 1;
	else if (start->orientation == 'W')
		data->player.dir_x = -1;
	else if (start->orientation == 'E')
		data->player.dir_x = 1;
	data->player.plane_x = -data->player.dir_y * 0.66;
	data->player.plane_y = data->player.dir_x * 0.66;
}

static int	init_texture(t_data *data, t_stexture *scene_texture,
							t_texture *texture)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, scene_texture->path,
		&texture->width, &texture->height);
	if (texture->img == NULL)
		return (0);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
		&texture->line_len, &texture->endian);
	return (texture->addr != NULL);
}
