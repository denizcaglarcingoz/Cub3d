#include "libraries.h"

void	did_trim(char *data, t_inp_data *inp)
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
	char	*temp1;
	char	*temp2;
	char	*temp3;
	char	*temp4;
	char	*temp5;
	char	*temp6;

	temp1 = ft_strtrim(inp->no_path, " ");
	temp2 = ft_strtrim(inp->so_path, " ");
	temp3 = ft_strtrim(inp->we_path, " ");
	temp4 = ft_strtrim(inp->ea_path, " ");
	temp5 = ft_strtrim(inp->floor_color_data, " ");
	temp6 = ft_strtrim(inp->ceiling_color_data, " ");
	free(inp->no_path);
	free(inp->so_path);
	free(inp->we_path);
	free(inp->ea_path);
	free(inp->floor_color_data);
	free(inp->ceiling_color_data);
	inp->no_path = temp1;
	inp->so_path = temp2;
	inp->we_path = temp3;
	inp->ea_path = temp4;
	inp->floor_color_data = temp5;
	inp->ceiling_color_data = temp6;
	did_trim(data, inp);
}

void	is_element(char *data, t_inp_data *inp)
{
	trim_elements(data, inp);
	is_xpm(data, inp);
	does_file_exist(data, inp);
}
