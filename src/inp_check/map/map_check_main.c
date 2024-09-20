/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:34 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:35 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	map_chars(char *data, int i)
{
	if (data[i] == '1')
		return (1);
	if (data[i] == '0')
		return (1);
	if (data[i] == ' ')
		return (1);
	if (data[i] == '\n')
		return (1);
	if (data[i] == 'W')
		return (1);
	if (data[i] == 'E')
		return (1);
	if (data[i] == 'N')
		return (1);
	if (data[i] == 'S')
		return (1);
	return (0);
}

void	map_char_check(char *data, int i, t_inp_data *inp)
{
	int	checks;

	checks = 0;
	while (data[i])
	{
		while (data[i] == '\n' || data[i] == ' ')
			(i)++;
		if (data[i] == 0)
			break ;
		if (map_chars(data, i) == 0)
			checks++;
		(i)++;
	}
	if (checks != 0)
	{
		inp_data_free(inp);
		ft_putstr_fd("Error\nMap Char Error\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	map_check_main(char *data, int *i, t_inp_data *inp)
{
	map_char_check(data, *i, inp);
	map_into_array(data, *i, inp);
	if (map_wall_check(inp) == 1)
	{
		free(data);
		inp_data_free(inp);
		ft_putstr_fd("Error\nWall Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
