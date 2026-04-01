/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:57:05 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 14:09:27 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "scene.h"

t_scene	*set_scene_log(t_scene *scene, const char *log)
{
	if (scene == NULL)
		return (NULL);
	scene->log = log;
	return (scene);
}

void	free_scene(t_scene *scene)
{
	size_t	i;

	if (scene == NULL)
		return ;
	i = 0;
	while (i < scene->map.rows_size)
		free(scene->map.rows[i++].squares);
	free(scene->map.rows);
	free(scene->textures.no.path);
	free(scene->textures.so.path);
	free(scene->textures.we.path);
	free(scene->textures.ea.path);
	ft_close(scene->textures.no.fd);
	ft_close(scene->textures.so.fd);
	ft_close(scene->textures.we.fd);
	ft_close(scene->textures.ea.fd);
	free(scene);
}
