#include "libraries.h"

int map_wall_check(t_inp_data *inp)
{
	if (char_check(inp) == 1)
		return (1);
	if (hor_border(inp) == 1)
		return (1);
	if (ver_border(inp) == 1)
		return (1);
	if (hor_check(inp) == 1)
		return (1);
	if (ver_check(inp) == 1)
		return (1);
	return (0);
}