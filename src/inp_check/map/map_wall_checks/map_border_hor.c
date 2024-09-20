/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_hor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:53 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:54 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	hor_last_check(t_inp_data *inp)
{
	int	j;
	int	i;

	i = 0;
	while (inp->map[i + 1])
	{
		j = 0;
		while (inp->map[i][j])
			j++;
		j--;
		while (j > 0 && inp->map[i][j] == ' ')
			j--;
		if (j == 0 && inp->map[i][j] == ' ')
			break ;
		if (inp->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	hor_first_check(t_inp_data *inp)
{
	int	j;
	int	i;

	i = 0;
	while (inp->map[i + 1])
	{
		j = 0;
		while (inp->map[i][j] == ' ')
			j++;
		if (inp->map[i][j] != '1' && inp->map[i][j] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	hor_border(t_inp_data *inp)
{
	if (hor_first_check(inp) == 1)
		return (1);
	if (hor_last_check(inp) == 1)
		return (1);
	return (0);
}
