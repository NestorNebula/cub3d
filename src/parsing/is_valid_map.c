/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:09:25 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/01 12:12:42 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "scene.h"

#define N_REACHED 0
#define I_REACHED 1
#define P_REACHED 2

static int	visit_map(t_map *map, int *map_copy, t_scene *scene);

static void	visit_square(t_map *map, int *map_copy, t_square *square,
				int status);

static void	check_square(t_scene *scene, int *map_copy, int c[2]);

static int	is_enclosed(t_map *map, int x, int y);

int	is_valid_map(t_map *map, t_scene *scene)
{
	size_t	i;
	int		*map_copy;
	int		rc;

	map->width = 0;
	i = 0;
	while (i < map->rows_size)
	{
		if (map->width < map->rows[i].length)
			map->width = map->rows[i].length;
		i++;
	}
	map_copy = ft_calloc(map->width * map->rows_size, sizeof(int));
	if (map_copy == NULL)
		return (!set_scene_log(scene, LOG_ALLOC_ERR));
	rc = visit_map(map, map_copy, scene);
	free(map_copy);
	return (rc);
}

static int	visit_map(t_map *map, int *map_copy, t_scene *scene)
{
	size_t	x;
	size_t	y;

	if (map->rows_size == 0 || map->width == 0)
		return (!set_scene_log(scene, LOG_EMPTY_MAP));
	visit_square(map, map_copy, map->start, P_REACHED);
	y = 0;
	while (y < map->rows_size)
	{
		x = 0;
		while (x < map->rows[y].length)
		{
			check_square(scene, map_copy, (int []){x, y});
			x++;
		}
		y++;
	}
	return (!scene->log);
}

static void	visit_square(t_map *map, int *map_copy, t_square *square,
				int status)
{
	int			c[2];
	t_square	*l;
	t_square	*u;
	t_square	*d;
	t_square	*r;

	get_square_coordinates(square, map, c, c + 1);
	if (status == P_REACHED && square->type != S_EMPTY)
		status--;
	if (map_copy[c[1] * map->width + c[0]] >= status)
		return ;
	map_copy[c[1] * map->width + c[0]] = status;
	l = square_from_coordinates(map, c[0] - 1, c[1]);
	u = square_from_coordinates(map, c[0], c[1] - 1);
	d = square_from_coordinates(map, c[0], c[1] + 1);
	r = square_from_coordinates(map, c[0] + 1, c[1]);
	if (l != NULL && l->type != S_SPACE)
		visit_square(map, map_copy, l, status);
	if (u != NULL && u->type != S_SPACE)
		visit_square(map, map_copy, u, status);
	if (d != NULL && d->type != S_SPACE)
		visit_square(map, map_copy, d, status);
	if (r != NULL && r->type != S_SPACE)
		visit_square(map, map_copy, r, status);
}

static void	check_square(t_scene *scene, int *map_copy, int c[2])
{
	t_map *const	map = &scene->map;
	t_square		*square;
	const int		x = c[0];
	const int		y = c[1];

	square = square_from_coordinates(map, x, y);
	if (square == NULL || square->type == S_SPACE)
		return ;
	if (map_copy[y * map->width + x] == N_REACHED)
		set_scene_log(scene, LOG_MULTI_ISLAND);
	if (square->type == S_EMPTY && !is_enclosed(map, x, y))
		set_scene_log(scene, LOG_NOT_ENCLOSED);
}

static int	is_enclosed(t_map *map, int x, int y)
{
	const t_square	*l = square_from_coordinates(map, x - 1, y);
	const t_square	*u = square_from_coordinates(map, x, y - 1);
	const t_square	*d = square_from_coordinates(map, x, y + 1);
	const t_square	*r = square_from_coordinates(map, x + 1, y);

	if (l == NULL || u == NULL || d == NULL || r == NULL)
		return (0);
	return (l->type != S_SPACE && u->type != S_SPACE
		&& d->type != S_SPACE && r->type != S_SPACE);
}
