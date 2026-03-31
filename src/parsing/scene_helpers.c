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

#include "scene.h"

t_scene	*set_scene_log(t_scene *scene, const char *log)
{
	if (scene == NULL)
		return (NULL);
	scene->log = log;
	return (scene);
}

void	free_scene(t_scene *scene);
