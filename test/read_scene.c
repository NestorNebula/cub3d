#include <fcntl.h>
#include <unistd.h>
#include "cut.h"
#include "scene.h"

#define TEST_FILE ".read_scene_test.test"

int		create_test_file(char *name, char *content);

void	test_valid_scene(char *name, char *scene_str);

void	test_invalid_scene(char *name, char *scene_str);

int	main(void)
{
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
	if (write(fd, content, i) != i)
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
