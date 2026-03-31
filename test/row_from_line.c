#include <stdlib.h>
#include <string.h>
#include "cut.h"
#include "scene.h"

#define ROW_LINE "1000 111"

int	main(void)
{
	t_unit_test	*unit_test;
	t_map		map;
	t_row		row;
	char		*line;
	size_t		i;

	unit_test = new_unit_test("row_from_line", false);
	cut_expect(row_from_line(ROW_LINE, &row, &map) == 1,
			unit_test, "returns 1 for valid line");
	cut_expect(row.length == strlen(ROW_LINE),
			unit_test, "sets row's length to line length");
	i = 0;
	line = ROW_LINE;
	while (line[i] != '\0')
	{
		cut_expect(row.squares[i].type == line[i],
				unit_test, "set square's type to expected type");
		i++;
	}
	free(row.squares);
	cut_expect(row_from_line("10X1", &row, &map) == 0,
			unit_test, "returns 0 for invalid line (invalid character)");
	cut_expect(row_from_line("10NS1", &row, &map) == 0,
			unit_test, "returns 0 for invalid line (multiple spawning positions");
	end_unit_test(unit_test);
}
