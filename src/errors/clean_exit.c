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

static void	free_textures(t_all *data)
{
	if (data->tex_no.img)
	{
		free(data->tex_no.img);
		data->tex_no.img = NULL;
	}
	if (data->tex_so.img)
	{
		free(data->tex_so.img);
		data->tex_so.img = NULL;
	}
	if (data->tex_we.img)
	{
		free(data->tex_we.img);
		data->tex_we.img = NULL;
	}
	if (data->tex_ea.img)
	{
		free(data->tex_ea.img);
		data->tex_ea.img = NULL;
	}
}

int	ft_exit(t_all *data)
{
	clean_exit(data, 0);
	return (0);
}

void	clean_exit(t_all *data, int checker)
{
	if (data == NULL)
		exit(0);
	if (data->libx.mlx && data->libx.win)
		mlx_destroy_window(data->libx.mlx, data->libx.win);
	if (data->libx.mlx)
	{
		mlx_destroy_display(data->libx.mlx);
		if (data->libx.mlx)
		{
			free(data->libx.mlx);
		}
	}
	if (data->libx.img)
	{
		free(data->libx.img);
		data->libx.img = NULL;
	}
	if (data->inp.map)
		free_map(data->inp.map);
	inp_data_free(&data->inp);
	free_textures(data);
	if (checker == 1)
		malloc_error();
	exit(0);
}
