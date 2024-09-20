/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_hor_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:45 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:46 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	hor_main_loop(char **map, int i, int j)
{
	while (map[i][j] && map[i][j] != '\n')
	{
		if (map[i][j] == ' ')
		{
			while (map[i][j] == ' ')
				j++;
			if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != '\0')
				return (1);
		}
		if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
			|| map[i][j] == 'W' || map[i][j] == 'E')
		{
			while (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E')
				j++;
			if (map[i][j] != '1')
				return (1);
		}
		if (map[i][j] != '\0')
			j++;
	}
	return (0);
}

int	hor_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			return (1);
		if (hor_main_loop(map, i, j) == 1)
			return (1);
		i++;
	}
	return (0);
}
