#include "libraries.h"

int hor_check(t_inp_data *inp)
{
	int	i;
	int	j;

	i = 0;
	while (inp->map[i + 1])
	{
		j = 0;
		while (inp->map[i][j] == ' ')
			j++;
		if (inp->map[i][j] != '1')
			return (1);
		while (inp->map[i][j] && inp->map[i][j] != '\n')
		{
			if (inp->map[i][j] == ' ')
			{
				while (inp->map[i][j] == ' ')
					j++;
				if (inp->map[i][j] != '1' && inp->map[i][j] != '\n' && inp->map[i][j] != '\0')
					return (1);
			}
			if (inp->map[i][j] == '0' || inp->map[i][j] == 'N' || inp->map[i][j] == 'S' || 
				inp->map[i][j] == 'W' || inp->map[i][j] == 'E')
			{
				while (inp->map[i][j] == '0' || inp->map[i][j] == 'N' || inp->map[i][j] == 'S' ||
					inp->map[i][j] == 'W' || inp->map[i][j] == 'E')
					j++;
				if (inp->map[i][j] != '1')
					return (1);
			}
			if (inp->map[i][j] != '\0')
				j++;
		}
		i++;
	}
	return (0);
}

