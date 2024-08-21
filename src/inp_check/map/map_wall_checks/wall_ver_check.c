#include "libraries.h"

int	ver_check(t_inp_data *inp)
{
	int	i;
	int	j;

	j = 0;
	while (inp->map[0][j + 1])
	{
		i = 0;
		while (inp->map[i][j] == ' ')
			i++;
		if (inp->map[i][j] != '1')
			return (1);
		while (inp->map[i][j])
		{
			if (inp->map[i][j] == ' ')
			{
				while (inp->map[i][j] == ' ')
					i++;
				if (inp->map[i][j] != '1' && inp->map[i][j] != '\n' && inp->map[i][j] != '\0')
					return (1);
			}
			if (inp->map[i][j] == '0' || inp->map[i][j] == 'N' || inp->map[i][j] == 'S' || 
				inp->map[i][j] == 'W' || inp->map[i][j] == 'E')
			{
				while (inp->map[i][j] == '0' || inp->map[i][j] == 'N' || inp->map[i][j] == 'S' ||
					inp->map[i][j] == 'W' || inp->map[i][j] == 'E')
					i++;
				if (inp->map[i][j] != '1')
					return (1);
			}
			if (inp->map[i][j] != '\0')
				i++;
		}
		j++;
	}
	return (0);
}
