#include "libraries.h"

void	map_data_copy(char *data, int i, t_inp_data *inp)
{
	int	j;
	int	k;

	j = 1;
	k = 1;
	while (data[i])
	{
		inp->map[j][k++] = data[i];
		if (data[i] == '\n')
		{
			j++;
			k = 1;
		}
		i++;
	}
	print_d_str(inp->map);
}