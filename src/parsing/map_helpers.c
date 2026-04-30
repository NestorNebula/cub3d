/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:10:24 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/01 12:12:41 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

int	get_square_coordinates(t_square *square, t_map *map, int *x, int *y)
{
	*y = 0;
	while ((size_t)(*y) < map->rows_size)
	{
		*x = 0;
		while ((size_t)(*x) < map->rows[*y].length)
		{
			if (map->rows[*y].squares + *x == square)
				return (1);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

t_square	*square_from_coordinates(t_map *map, int x, int y)
{
	t_row	*row;

	if (x < 0 || y < 0 || (size_t) y >= map->rows_size)
		return (NULL);
	row = map->rows + y;
	if ((size_t) x >= row->length)
		return (NULL);
	return (row->squares + x);
}

bool		is_walkable(t_map *map, int x, int y)
{
	t_square *square;

	square = square_from_coordinates(map, x, y);
	if (square == NULL)
		return (NULL);
	return (square->type != S_WALL);
}
