#include "libraries.h"

void did_trim(char *data, t_inp_data *inp)
{
	if (inp->no_path == NULL)
		element_check_err(data, inp, "trim error");
	if (inp->so_path == NULL)
		element_check_err(data, inp, "trim error");
	if (inp->we_path == NULL)
		element_check_err(data, inp, "trim error");
	if (inp->ea_path == NULL)
		element_check_err(data, inp, "trim error");
	if (inp->floor_color_data == NULL)
		element_check_err(data, inp, "trim error");
	if (inp->ceiling_color_data == NULL)
		element_check_err(data, inp, "trim error");
}

void	trim_elements(char *data, t_inp_data *inp)
{
	inp->no_path = ft_strtrim(inp->no_path, " ");
	inp->so_path = ft_strtrim(inp->so_path, " ");
	inp->we_path = ft_strtrim(inp->we_path, " ");
	inp->ea_path = ft_strtrim(inp->ea_path, " ");
	inp->floor_color_data = ft_strtrim(inp->floor_color_data, " ");
	inp->ceiling_color_data = ft_strtrim(inp->ceiling_color_data, " ");
	did_trim(data, inp);
}

void	is_element(char *data, t_inp_data *inp)
{
	trim_elements(data, inp);
	is_xpm(data, inp);
	does_file_exist(data, inp);
}