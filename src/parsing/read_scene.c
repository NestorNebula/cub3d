/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:54:02 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 14:46:15 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "scene.h"

#define EXT ".cub"
#define EXT_LEN 4
#define TEXTURES_SIZE 6

static void	init_scene(t_scene *scene);

static void	read_content(t_scene *scene, int fd);

static void	read_map(t_scene *scene, int fd, char *first_line);

static int	is_texture(char *line);

t_scene	*read_scene(char *filepath)
{
	t_scene	*scene;
	char	*ext;
	int		fd;

	if (filepath == NULL)
		return (NULL);
	scene = malloc(sizeof(t_scene));
	if (scene == NULL)
		return (NULL);
	init_scene(scene);
	fd = open(filepath, O_RDWR);
	if (fd == -1)
		set_scene_log(scene, "Error\nCan't open scene file");
	ext = ft_strrchr(filepath, '.');
	if (ft_strlen(filepath) < EXT_LEN + 1 || ext == NULL
		|| ft_strncmp(ext, EXT, EXT_LEN + 1) != 0 || *(ext - 1) == '/')
		set_scene_log(scene, "Error\nInvalid file extension");
	if (!scene->log)
		read_content(scene, fd);
	ft_close(fd);
	if (is_valid_scene(scene))
		return (scene);
	free_scene(scene);
	return (NULL);
}

static void	init_scene(t_scene *scene)
{
	scene->log = NULL;
	ft_bzero(&scene->map, sizeof(t_map));
	ft_bzero(&scene->textures, sizeof(t_textures));
	scene->textures.no.fd = -1;
	scene->textures.so.fd = -1;
	scene->textures.we.fd = -1;
	scene->textures.ea.fd = -1;
	scene->textures.f = 255 << 24;
	scene->textures.c = 255 << 24;
}

static void	read_content(t_scene *scene, int fd)
{
	char	*line;

	if (fd == -1)
		return ;
	line = get_next_line(fd);
	while (line != NULL && (line[0] == '\n' || is_texture(line)) && !scene->log)
	{
		if (line[0] != '\n')
			texture_from_line(line, scene);
		free(line);
		line = get_next_line(fd);
	}
	read_map(scene, fd, line);
}

static void	read_map(t_scene *scene, int fd, char *first_line)
{
	t_row	*rows;
	char	*line;

	line = first_line;
	while (line != NULL && line[0] != '\0' && line[0] != '\n' && !scene->log)
	{
		rows = ft_realloc(scene->map.rows, scene->map.rows_size * sizeof(t_row), (scene->map.rows_size + 1) * sizeof(t_row));
		if (rows == NULL)
			set_scene_log(scene, "Error\nAllocation error during map parsing");
		else
		{
			scene->map.rows = rows;
			row_from_line(line, &scene->map.rows[scene->map.rows_size++], scene);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL && !scene->log)
		set_scene_log(scene, "Error\nMap content doesn't end scene file");
	free(line);
}

static int	is_texture(char *line)
{
	const char	*textures[6] = {
		"NO ", "SO ", "WE ", "EA ", "F ", "C "
	};
	size_t		i;

	i = 0;
	while (i < TEXTURES_SIZE
		&& ft_strncmp(line, textures[i], ft_strlen(textures[i])) != 0)
		i++;
	return (i != TEXTURES_SIZE);
}
