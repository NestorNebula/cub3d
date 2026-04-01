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
#define SCENE_NO_MAP SCENES_PATH "scene_no_map.cub"
#define SCENE_NO_TEXTURE SCENES_PATH "scene_no_texture.cub"

void	test_valid_scene(char *name, char *filepath);

void	test_invalid_scene(char *name, char *filepath);

int	main(void)
{
	test_valid_scene("works for valid scene with basic scene", BASIC_SCENE);
	test_valid_scene("works for valid scene with default scene", DEFAULT_SCENE);
	test_invalid_scene("handles scene with no map", SCENE_NO_MAP);
	test_invalid_scene("handles scene with no textures", SCENE_NO_TEXTURE);
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
