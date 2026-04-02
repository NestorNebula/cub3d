/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_from_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:54:45 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 15:50:02 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "scene.h"

static t_texture	*find_texture(char *line, t_scene *scene);

static int			rgb_texture_from_line(char *line, t_scene *scene);

static int			read_rgb(char **rgb_split, int *rgb_texture,
						t_scene *scene);

int	texture_from_line(char *line, t_scene *scene)
{
	t_texture	*texture;
	char		*path;

	if (ft_strchr(line, '\n') != NULL)
		*ft_strchr(line, '\n') = '\0';
	texture = find_texture(line, scene);
	if (texture == NULL)
		return (rgb_texture_from_line(line, scene));
	if (texture->path != NULL)
		return (!set_scene_log(scene, LOG_DUP_TEXTURE));
	path = line + 2;
	while (*path != '\0' && ft_strchr(" \t", *path))
		path++;
	texture->path = ft_strdup(path);
	if (texture->path == NULL)
		return (!set_scene_log(scene, LOG_ALLOC_ERR));
	texture->fd = open(texture->path, O_RDWR);
	if (texture->fd == -1)
	{
		free(texture->path);
		texture->path = NULL;
		return (!set_scene_log(scene, LOG_TEXTURE_FILE_ERR));
	}
	return (1);
}

static t_texture	*find_texture(char *line, t_scene *scene)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (&scene->textures.no);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (&scene->textures.so);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (&scene->textures.we);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (&scene->textures.ea);
	return (NULL);
}

static int	rgb_texture_from_line(char *line, t_scene *scene)
{
	char	**rgb_split;
	size_t	split_size;
	int		*rgb_texture;
	int		rc;

	if (line[0] == 'F')
		rgb_texture = &scene->textures.f;
	else
		rgb_texture = &scene->textures.c;
	if (!(*rgb_texture & (255 << 24)))
		return (!set_scene_log(scene, LOG_DUP_TEXTURE));
	rgb_split = ft_split_set(line + 1, " \t,");
	if (rgb_split == NULL)
		return (!set_scene_log(scene, LOG_ALLOC_ERR));
	split_size = 0;
	while (rgb_split[split_size] != NULL)
		split_size++;
	if (split_size != 3)
	{
		ft_free_arr(rgb_split, free);
		return (!set_scene_log(scene, LOG_BAD_RGB));
	}
	rc = read_rgb(rgb_split, rgb_texture, scene);
	ft_free_arr(rgb_split, free);
	return (rc);
}

static int	read_rgb(char **rgb_split, int *rgb_texture,
				t_scene *scene)
{
	int	r;
	int	g;
	int	b;

	if (ft_get_number(rgb_split[0], &r) == 0 || r < 0 || r > 255
		|| ft_get_number(rgb_split[1], &g) == 0 || g < 0 || g > 255
		|| ft_get_number(rgb_split[2], &b) == 0 || b < 0 || b > 255)
		return (!set_scene_log(scene, LOG_BAD_RGB));
	*rgb_texture = (r << 16) + (g << 8) + b;
	return (1);
}
