/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 12:08:42 by nhoussie          #+#    #+#             */
/*   Updated: 2026/05/05 07:12:20 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# define LOG_EMPTY_ROW "Error\nEmpty row in map"
# define LOG_ALLOC_ERR "Error\nAllocation error"
# define LOG_MULTI_SPAWN "Error\nMultiple spawning positions"
# define LOG_UNEXPECTED_CHAR "Error\nUnexpected character in map"
# define LOG_MISSING_TEXTURE "Error\nMissing texture"
# define LOG_NO_SPAWN "Error\nNo spawning position"
# define LOG_FILE_ERR "Error\nCan't open scene file"
# define LOG_TEXTURE_FILE_ERR "Error\nCan't open texture file"
# define LOG_BAD_EXT "Error\nInvalid file extension"
# define LOG_MAP_NOT_END "Error\nMap content doesn't end scene file"
# define LOG_DUP_TEXTURE "Error\nDuplicate texture"
# define LOG_BAD_RGB "Error\nColor not in RGB format"
# define LOG_NO_MAP "Error\nNo map found in scene file"
# define LOG_MULTI_ISLAND "Error\nMultiple islands in map"
# define LOG_NOT_ENCLOSED "Error\nSquares not enclosed by walls"
# define LOG_BAD_TEX_FORMAT "Error\nInvalid texture line format"

# include <stddef.h>
# include <stdbool.h>

# define SQUARE_TYPES "01 "
# define ORIENTATION_TYPES "NSEW"

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
	size_t		width;
	t_row		*rows;
	t_square	*start;
}	t_map;

typedef struct s_stexture
{
	char	*path;
	int		fd;
}	t_stexture;

typedef struct s_textures
{
	t_stexture	no;
	t_stexture	so;
	t_stexture	we;
	t_stexture	ea;
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
t_scene		*read_scene(char *filepath);

/**
 * Converts a given line into a texture.
 *
 * @param line A string
 * @param scene A pointer to a scene structure,
 * in which the texture read will be stored
 * @return 1 on success, 0 on error
 */
int			texture_from_line(char *line, t_scene *scene);

/**
 * Converts a given line into a row structure.
 *
 * @param line A string
 * @param row A pointer to the row structure to set
 * @param scene A pointer to the scene structure in which the row will be stored
 * @return 1 on success, 0 on error
 */
int			row_from_line(char *line, t_row *row, t_scene *scene);

/**
 * Checks if a given scene respects the scene rules.
 *
 * @param scene A pointer to a scene structure
 * @return 1 if the scene is valid, 0 otherwise
 */
int			is_valid_scene(t_scene *scene);

/**
 * Checks if a given map respects the map rules.
 *
 * @param map A pointer to a map structure
 * @param scene A pointer to a scene structure to which the map belongs
 * @return 1 if the map is valid, 0 otherwise
 */
int			is_valid_map(t_map *map, t_scene *scene);

/**
 * Sets a scene's log member to a given string.
 *
 * @param scene A poiner to a scene structure
 * @param log A pointer to a string literal
 * @return The given scene
 */
t_scene		*set_scene_log(t_scene *scene, const char *log);

/**
 * Frees a scene structure
 *
 * @param scene A pointer to a scene structure
 */
void		free_scene(t_scene *scene);

/**
 * Gets the coordinates of a given square in a map.
 *
 * @param square A pointer to a square structure
 * @param map A pointer to a map structure
 * @param x A pointer to an integer where
 * the square's position in the x axis will be stored
 * @param y A pointer to an integer where
 * the square's position in the y axis will be stored
 * @return 1 if the square was found, 0 otherwise
 */
int			get_square_coordinates(t_square *square, t_map *map,
				int *x, int *y);

/**
 * Searches inside a map for a square at given coordinates.
 *
 * @param map A pointer to a map structure
 * @param x The position of the searched square in the x axis
 * @param y The position of the searched square in the y axis
 * @return A pointer to a square structure if found, a NULL pointer otherwise
 */
t_square	*square_from_coordinates(t_map *map, int x, int y);

/**
 * Searches inside a map for a square at given coordinates.
 * If it exits, checks if that square can be walked on,
 * i.e. that square is not a wall.
 *
 * @param map A pointer to a map structure
 * @param x The position of the searched square in the x axis
 * @param y The position of the searched square in the y axis
 * @return A boolean defining if a walkable square exists at coordinates x,y
 */
bool		is_walkable(t_map *map, int x, int y);

/**
 * Counts the number of occurrence of a character in a string.
 *
 * @param str A string
 * @param c The character to count
 * @return The number of times the character appears in the string
 */
int			str_count(char *str, char c);

#endif // !SCENE_H
