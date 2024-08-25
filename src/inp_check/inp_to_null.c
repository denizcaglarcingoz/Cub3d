#include "libraries.h"

void	inp_to_null(t_inp_data *inp)
{
	inp->no_path = NULL;
	inp->so_path = NULL;
	inp->ea_path = NULL;
	inp->we_path = NULL;
	inp->ceiling_color_data = NULL;
	inp->floor_color_data = NULL;
	inp->floor_color = -1;
	inp->ceiling_color = -1;
	inp->map = NULL;
}
