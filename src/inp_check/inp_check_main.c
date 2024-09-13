#include "libraries.h"

void	inp_check_main(char *file_name, t_inp_data *inp)
{
	char	*data;

	file_name_check(file_name);
	data = get_file_data(file_name);
	data_check(data, inp);
	set_p_pos(inp);
	color_set(inp);
	printf("ceilin color: %d\n", inp->ceiling_color);
	printf("floor color: %d\n", inp->floor_color);
	printf("ceiling color data: %s\n", inp->ceiling_color_data);
	printf("floor color data: %s\n", inp->floor_color_data);
}
