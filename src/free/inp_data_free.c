#include "libraries.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
}

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
		(free_map(inp->map), free(inp->map));
	if (inp->floor_color_data)
		free(inp->floor_color_data);
	if (inp->ceiling_color_data)
		free(inp->ceiling_color_data);
}
