/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:08:42 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 14:01:17 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include <stddef.h>

#define SQUARE_TYPES "01 "
#define ORIENTATION_TYPES "NSEW"

typedef enum e_square_type
{
	S_EMPTY = '0',
	S_WALL = '1',
	S_SPACE = ' ',
}	t_square_type;

typedef struct s_square
{
	t_square_type	type;
	char			orientation;
}	t_square;

typedef struct s_row
{
	size_t		length;
	t_square	*squares;
}	t_row;

typedef struct s_map
{
	size_t		rows_size;
	t_row		*rows;
	t_square	*start;
}	t_map;

typedef struct s_texture
{
	char	*path;
	int		fd;
}	t_texture;

typedef struct s_textures
{
	t_texture	no;
	t_texture	so;
	t_texture	we;
	t_texture	ea;
	int			f;
	int			c;
}	t_textures;

typedef struct s_scene
{
	t_map		map;
	t_textures	textures;
	const char	*log;
}	t_scene;

/**
 * Reads a scene from a given file.
 *
 * @param filepath The path to the scene's file
 * @return A pointer to a scene structure on success,
 * a NULL pointer otherwise
 */
t_scene	*read_scene(char *filepath);

/**
 * Converts a given line into a texture.
 *
 * @param line A string
 * @param scene A pointer to a scene structure,
 * in which the texture read will be stored
 * @return 1 on success, 0 on error
 */
int		texture_from_line(char *line, t_scene *scene);

/**
 * Converts a given line into a row structure.
 *
 * @param line A string
 * @param row A pointer to the row structure to set
 * @param scene A pointer to the scene structure in which the row will be stored
 * @return 1 on success, 0 on error
 */
int		row_from_line(char *line, t_row *row, t_scene *scene);

/**
 * Checks if a given scene respects the scene rules.
 *
 * @param scene A pointer to a scene structure
 * @return 1 if the scene is valid, 0 otherwise
 */
int		is_valid_scene(t_scene *scene);

/**
 * Frees a scene structure
 *
 * @param scene A pointer to a scene structure
 */
void	free_scene(t_scene *scene);

#endif // !SCENE_H
