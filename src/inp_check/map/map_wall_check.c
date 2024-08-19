#include "libraries.h"

int map_wall_check(t_inp_data *inp)
{
	int checks;
	int i;
	int j;

	checks = 0;
	i = 0;
	while (inp->map[0][i] || inp->map[0][i] != '\n')
	{
		if (inp->map[0][i] != '1' || inp->map[0][i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (inp->map[i])
	{
		j = 0;
		while (inp->map[i][j] || inp->map[i][j] != '\n')
		{
			while (inp->map[i][j] == ' ')
				j++;
			if (inp->map[i][j] != '1')
				return (1);				
			j++;
		}
		i++;
	}
}