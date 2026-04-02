/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row_from_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:55:14 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 14:46:15 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "scene.h"

static void	square_from_char(char c, t_square *square, t_scene *scene);

int	row_from_line(char *line, t_row *row, t_scene *scene)
{
	size_t	i;

	if (ft_strchr(line, '\n') != NULL)
		*ft_strchr(line, '\n') = '\0';
	row->length = ft_strlen(line);
	if (row->length == 0)
		return (!set_scene_log(scene, LOG_EMPTY_ROW));
	row->squares = ft_calloc(row->length, sizeof(t_square));
	if (row->squares == NULL)
		return (!set_scene_log(scene, LOG_ALLOC_ERR));
	i = 0;
	while (i < row->length && !scene->log)
	{
		square_from_char(line[i], row->squares + i, scene);
		i++;
	}
	if (scene->log)
	{
		free(row->squares);
		row->squares = NULL;
	}
	return (!scene->log);
}

static void	square_from_char(char c, t_square *square, t_scene *scene)
{
	if (ft_strchr(SQUARE_TYPES, c))
	{
		square->type = c;
		square->orientation = '\0';
	}
	else if (ft_strchr(ORIENTATION_TYPES, c))
	{
		if (scene->map.start != NULL)
			set_scene_log(scene, LOG_MULTI_SPAWN);
		else
		{
			square->type = S_EMPTY;
			square->orientation = c;
			scene->map.start = square;
		}
	}
	else
		set_scene_log(scene, LOG_UNEXPECTED_CHAR);
}
