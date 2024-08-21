#include "libraries.h"

int	ver_main_loop(char **map, int i, int j)
{
	while (map[i][j])
	{
		if (map[i][j] == ' ')
		{
			while (map[i][j] == ' ')
				i++;
			if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != '\0')
				return (1);
		}
		if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'E')
		{
			while (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				i++;
			if (map[i][j] != '1')
				return (1);
		}
		if (map[i][j] != '\0')
			i++;
	}
	return (0);
}

int	ver_check(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[0][j + 1])
	{
		i = 0;
		while (map[i][j] == ' ')
			i++;
		if (map[i][j] != '1')
			return (1);
		if (ver_main_loop(map, i, j) == 1)
			return (1);
		j++;
	}
	return (0);
}
