/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:56:24 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 17:46:58 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "scene.h"

static void	print_log(t_scene *scene);

int	is_valid_scene(t_scene *scene)
{
	if (!scene->log)
	{
		if (scene->textures.no.path == NULL
			|| scene->textures.so.path == NULL
			|| scene->textures.we.path == NULL
			|| scene->textures.ea.path == NULL
			|| (scene->textures.f & (255 << 24)) != 0
			|| (scene->textures.c & (255 << 24)) != 0)
			set_scene_log(scene, LOG_MISSING_TEXTURE);
	}
	if (!scene->log && scene->map.rows_size == 0)
		set_scene_log(scene, LOG_NO_MAP);
	if (!scene->log && scene->map.start == NULL)
		set_scene_log(scene, LOG_NO_SPAWN);
	if (!scene->log)
		is_valid_map(&scene->map, scene);
	print_log(scene);
	return (scene->log == NULL);
}

static void	print_log(t_scene *scene)
{
	if (!scene->log)
		return ;
	ft_dprintf(STDERR_FILENO, "%s\n", scene->log);
}
