#include <fcntl.h>
#include <unistd.h>
#include "cut.h"
#include "scene.h"

#define NO_PATH ".no_path_test"
#define SO_PATH ".so_path_test"
#define WE_PATH ".we_path_test"
#define EA_PATH ".ea_path_test"

#define SCENES_PATH "scenes/"

#define BASIC_SCENE SCENES_PATH "basic_scene.cub"
#define DEFAULT_SCENE SCENES_PATH "default_scene.cub"
#define CUBE_SCENE SCENES_PATH "scene.cube"
#define SCENE_DONUT_SPACE SCENES_PATH "scene_donut_space.cub"
#define SCENE_DONUT_ZERO SCENES_PATH "scene_donut_zero.cub"
#define SCENE_DUPLICATE_TEXTURE SCENES_PATH "scene_duplicate_texture.cub"
#define SCENE_INVALID_CHAR SCENES_PATH "scene_invalid_char.cub"
#define SCENE_INVALID_DONUT SCENES_PATH "scene_invalid_donut.cub"
#define SCENE_INVALID_RGB SCENES_PATH "scene_invalid_rgb.cub"
#define SCENE_MAP_EMPTY_LINE SCENES_PATH "scene_map_empty_line.cub"
#define SCENE_MAP_NON_ENCLOSED SCENES_PATH "scene_map_non_enclosed.cub"
#define SCENE_MAP_NON_ENCLOSED_VOID SCENES_PATH "scene_map_non_enclosed_void.cub"
#define SCENE_MAP_PADDING SCENES_PATH "scene_map_padding.cub"
#define SCENE_MISSING_TEXTURE SCENES_PATH "scene_missing_texture.cub"
#define SCENE_MULTIPLE_SPAWNS SCENES_PATH "scene_multiple_spawns.cub"
#define SCENE_NO_MAP SCENES_PATH "scene_no_map.cub"
#define SCENE_NO_SPAWN SCENES_PATH "scene_no_spawn.cub"
#define SCENE_NO_TEXTURE SCENES_PATH "scene_no_texture.cub"
#define SCENE_SHUFFLED_TEXTURES SCENES_PATH "scene_shuffled_textures.cub"
#define SCENE_VALID_NON_RECTANGULAR SCENES_PATH "scene_valid_non_rectangular.cub"
#define SCENE_WRONG_RGB SCENES_PATH "scene_wrong_rgb.cub"

void	test_valid_scene(char *name, char *filepath);

void	test_invalid_scene(char *name, char *filepath);

int	main(void)
{
	test_valid_scene("works for valid scene with basic scene", BASIC_SCENE);
	test_valid_scene("works for valid scene with default scene", DEFAULT_SCENE);
	test_invalid_scene("handles wrong file extension", CUBE_SCENE);
	test_valid_scene("works for donut with spaces", SCENE_DONUT_SPACE);
	test_valid_scene("works for donut with zeros", SCENE_DONUT_ZERO);
	test_invalid_scene("handles duplicate textures", SCENE_DUPLICATE_TEXTURE);
	test_invalid_scene("handles invalid characters", SCENE_INVALID_CHAR);
	test_invalid_scene("handles invalid donut", SCENE_INVALID_DONUT);
	test_invalid_scene("handles invalid rgb format", SCENE_INVALID_RGB);
	test_invalid_scene("handles empty lines in map", SCENE_MAP_EMPTY_LINE);
	test_invalid_scene("handles non-enclosed map", SCENE_MAP_NON_ENCLOSED);
	test_invalid_scene("handles void non-enclosed in map", SCENE_MAP_NON_ENCLOSED_VOID);
	test_valid_scene("works for valid map with padding", SCENE_MAP_PADDING);
	test_invalid_scene("handles missing texture", SCENE_MISSING_TEXTURE);
	test_invalid_scene("handles multiple spawns", SCENE_MULTIPLE_SPAWNS);
	test_invalid_scene("handles scene with no map", SCENE_NO_MAP);
	test_invalid_scene("handles scene with no spawn", SCENE_NO_SPAWN);
	test_invalid_scene("handles scene with no textures", SCENE_NO_TEXTURE);
	test_valid_scene("works for scene with shuffled texture", SCENE_SHUFFLED_TEXTURES);
	test_valid_scene("works for non-rectangular map", SCENE_VALID_NON_RECTANGULAR);
	test_invalid_scene("handles wrong rgb color", SCENE_WRONG_RGB);
}

void	test_valid_scene(char *name, char *filepath)
{
	t_unit_test	*unit_test;
	t_scene		*scene;

	unit_test = new_unit_test(name, false);
	scene = read_scene(filepath);
	cut_assert(scene != NULL, unit_test, "returns non-null pointer for valid scene");
	free_scene(scene);
	end_unit_test(unit_test);
}

void	test_invalid_scene(char *name, char *filepath)
{
	t_unit_test	*unit_test;
	t_scene		*scene;

	unit_test = new_unit_test(name, false);
	scene = read_scene(filepath);
	cut_expect(scene == NULL, unit_test, "returns null pointer for invalid scene");
	free_scene(scene);
	end_unit_test(unit_test);
}
