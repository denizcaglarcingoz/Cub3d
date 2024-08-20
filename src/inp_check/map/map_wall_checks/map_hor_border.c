#include "libraries.h"

int border_check(t_inp_data *inp, int i)
{
	int j;

	j = 0;
	while (inp->map[i][j] || inp->map[i][j] != '\n')
	{
		if (inp->map[i][j] != '1' || inp->map[i][j] != ' ')
			return (1);
		j++;
	}
	return (0);
}

int	hor_border(t_inp_data *inp)
{
	int i;
	int border;

	border = border_check(inp, 0);
	i = 0;
	while (inp->map[i] != NULL)
		i++;
	border = border_check(inp, i - 1);
	return (border);
}