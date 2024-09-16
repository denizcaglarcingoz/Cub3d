#include "libraries.h"

void	inp_data_free(t_inp_data *inp)
{
	if (inp->no_path)
		free(inp->no_path);
	if (inp->so_path)
		free(inp->so_path);
	if (inp->ea_path)
		free(inp->ea_path);
	if (inp->we_path)
		free(inp->we_path);
	if (inp->map)
		free(inp->map);
	if (inp->ceiling_color_data)
		free(inp->ceiling_color_data);
	if (inp->floor_color_data)
		free(inp->floor_color_data);
	
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
