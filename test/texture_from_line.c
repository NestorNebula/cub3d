#include <stdlib.h>
#include <string.h>
#include "cut.h"
#include "scene.h"

#define T_PATH "textures/"
#define NO_PATH T_PATH "no.xpm"
#define SO_PATH T_PATH "so.xpm"
#define WE_PATH T_PATH "we.xpm"
#define EA_PATH T_PATH "ea.xpm"
#define F_R "220"
#define F_G "100"
#define F_B "0"
#define C_R "225"
#define C_G "30"
#define C_B "0"

int	main(void)
{
	t_unit_test	*unit_test;
	t_scene		scene;

	unit_test = new_unit_test("texture_from_line", false);
	cut_expect(texture_from_line("NO " NO_PATH, &scene) != 0,
			unit_test, "returns 1 after setting NO texture");
	cut_expect(strcmp(scene.textures.no.path, NO_PATH) == 0,
			unit_test, "stores correct path for NO texture");
	cut_expect(texture_from_line("SO " SO_PATH, &scene) != 0,
			unit_test, "returns 1 after setting SO texture");
	cut_expect(strcmp(scene.textures.so.path, SO_PATH) == 0,
			unit_test, "stores correct path for SO texture");
	cut_expect(texture_from_line("WE " WE_PATH, &scene) != 0,
			unit_test, "returns 1 after setting WE texture");
	cut_expect(strcmp(scene.textures.we.path, WE_PATH) == 0,
			unit_test, "stores correct path for WE texture");
	cut_expect(texture_from_line("EA " EA_PATH, &scene) != 0,
			unit_test, "returns 1 after setting EA texture");
	cut_expect(strcmp(scene.textures.ea.path, EA_PATH) == 0,
			unit_test, "stores correct path for EA texture");
	cut_expect(texture_from_line("F " F_R "," F_G "," F_B, &scene) != 0,
			unit_test, "returns 1 after setting F color");
	cut_expect((scene.textures.f >> 16 & 255) == atoi(F_R),
			unit_test, "sets F's red value correctly");
	cut_expect((scene.textures.f >> 8 & 255) == atoi(F_G),
			unit_test, "sets F's green value correctly");
	cut_expect((scene.textures.f & 255) == atoi(F_B),
			unit_test, "sets F's blue value correctly");
	cut_expect(texture_from_line("C " C_R "," C_G "," C_B, &scene) != 0,
			unit_test, "returns 1 after setting C color");
	cut_expect((scene.textures.c >> 16 & 255) == atoi(C_R),
			unit_test, "sets C's red value correctly");
	cut_expect((scene.textures.c >> 8 & 255) == atoi(C_G),
			unit_test, "sets C's green value correctly");
	cut_expect((scene.textures.c & 255) == atoi(C_B),
			unit_test, "sets C's blue value correctly");
	free(scene.textures.no.path);
	free(scene.textures.so.path);
	free(scene.textures.we.path);
	free(scene.textures.ea.path);

	cut_expect(texture_from_line("A" " NA", &scene) == 0,
			unit_test, "returns 0 for invalid identifier");
	cut_expect(texture_from_line("NO " "no_such_file", &scene) == 0,
			unit_test, "returns 0 for invalid filepath");
	cut_expect(texture_from_line("F" "255,255,256", &scene) == 0,
			unit_test, "returns 0 for invalid color (overflow)");
	cut_expect(texture_from_line("F" "255,-1,255", &scene) == 0,
			unit_test, "returns 0 for invalid color (negative)");
	cut_expect(texture_from_line("F" "255,255,255,255", &scene) == 0,
			unit_test, "returns 0 for invalid color (longer than RGB format)");
	cut_expect(texture_from_line("F" "255,255", &scene) == 0,
			unit_test, "returns 0 for invalid color (shorter than RGB format)");
	end_unit_test(unit_test);
}
