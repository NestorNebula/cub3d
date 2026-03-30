#include <fcntl.h>
#include <unistd.h>
#include "cut.h"
#include "scene.h"

#define TEST_FILE ".read_scene_test.test"
#define NO_PATH ".no_path_test"
#define SO_PATH ".so_path_test"
#define WE_PATH ".we_path_test"
#define EA_PATH ".ea_path_test"

#define MAP_TEXTURES "NO " NO_PATH \
	"\nSO " SO_PATH \
	"\nWE " WE_PATH \
	"\nEA " EA_PATH \
	"\n\nF 220,100,0\n" \
	"C 225,30,0\n\n"

#define VALID_MAP_1 "111111\n" \
	"100101\n" \
	"101001\n" \
	"1100N1\n" \
	"111111\n"

#define VALID_MAP_2 "1111111111111111111111111\n" \
	"1000000000110000000000001\n" \
	"1011000001110000000000001\n" \
	"1001000000000000000000001\n" \
	"111111111011000001110000000000001\n" \
	"100000000011000001110111111111111\n" \
	"11110111111111011100000010001\n" \
	"11110111111111011101010010001\n" \
	"11000000110101011100000010001\n" \
	"10000000000000001100000010001\n" \
	"10000000000000001101010010001\n" \
	"11000001110101011111011110N0111\n" \
	"11110111 1110101 101111010001\n" \
	"11111111 1111111 111111111111\n"

int		create_test_file(char *name, char *content);

void	test_valid_scene(char *name, char *scene_str);

void	test_invalid_scene(char *name, char *scene_str);

int	main(void)
{
	if (create_test_file(NO_PATH, "") == -1
		|| create_test_file(SO_PATH, "") == -1
		|| create_test_file(WE_PATH, "") == -1
		|| create_test_file(EA_PATH, ""))
		return (0);
	test_valid_scene("works for valid scene with basic map", MAP_TEXTURES VALID_MAP_1);
	test_valid_scene("works for valid scene with bigger map", MAP_TEXTURES VALID_MAP_2);
	test_invalid_scene("handles scene with no map", MAP_TEXTURES);
	test_invalid_scene("handles scene with no textures", VALID_MAP_1);
	unlink(NO_PATH);
	unlink(SO_PATH);
	unlink(WE_PATH);
	unlink(EA_PATH);
}

int		create_test_file(char *name, char *content)
{
	int	fd;
	size_t	i;

	if (content == NULL)
		return (-1);
	fd = open(name, O_WRONLY);
	if (fd == -1)
		return (-1);
	i = 0;
	while (content[i] != '\0')
		i++;
	if (write(fd, content, i) != (int) i)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}

void	test_valid_scene(char *name, char *scene_str)
{
	t_unit_test	*unit_test;
	t_scene		*scene;

	unit_test = new_unit_test(name, false);
	cut_assert(create_test_file(TEST_FILE, scene_str) != -1, unit_test, "creates scene file");
	scene = read_scene(TEST_FILE);
	cut_expect(scene != NULL, unit_test, "returns non-null pointer for valid scene");
	unlink(TEST_FILE);
	free_scene(scene);
	end_unit_test(unit_test);
}

void	test_invalid_scene(char *name, char *scene_str)
{
	t_unit_test	*unit_test;
	t_scene		*scene;

	unit_test = new_unit_test(name, false);
	cut_assert(create_test_file(TEST_FILE, scene_str) != -1, unit_test, "creates scene file");
	scene = read_scene(TEST_FILE);
	cut_expect(scene == NULL, unit_test, "returns null pointer for invalid scene");
	unlink(TEST_FILE);
	free_scene(scene);
	end_unit_test(unit_test);
}
