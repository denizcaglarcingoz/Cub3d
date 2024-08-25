#include "libraries.h"

void	map_malloc_fail(char *data, t_inp_data *inp)
{
	ft_putstr_fd("Malloc_Error", 2);
	free(data);
	inp_data_free(inp);
	exit(EXIT_FAILURE);
}

void	map_malloc_fail_d(char *data, t_inp_data *inp, int i)
{
	while (i >= 0)
		free(inp->map[i--]);
	free(inp->map);
	map_malloc_fail(data, inp);
}

void	map_space_fill(int *size, t_inp_data *inp)
{
	int	i;
	int	j;

	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			inp->map[i][j] = ' ';
			j++;
		}
		inp->map[i][j] = '\0';
		i++;
	}
	i = 0;
	while (i <= size[1])
	{
		inp->map[size[0]][i] = '\0';
		i++;
	}
}

void	map_init(char *data, int *size, t_inp_data *inp)
{
	int	i;

	inp->map = (char **)malloc(sizeof(char *) * (size[0] + 2));
	if (inp->map == NULL)
		map_malloc_fail(data, inp);
	inp->map[size[0] + 1] = NULL;
	i = 0;
	while (i <= size[0])
	{
		inp->map[i] = (char *)malloc(sizeof(char) * size[1] + 1);
		if (inp->map[i] == NULL)
			map_malloc_fail_d(data, inp, i);
		i++;
	}
	inp->map_height = size[0];
	inp->map_width = size[1];
	printf("map_height: %d\n", inp->map_height);
	printf("map_width: %d\n", inp->map_width);
	map_space_fill(size, inp);
}
