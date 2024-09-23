/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:51 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:52 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	ver_last_check(t_inp_data *inp)
{
	int	j;
	int	i;

	i = 0;
	while (inp->map[0][i + 1])
	{
		j = 0;
		while (inp->map[j][i] != '\0')
			j++;
		j--;
		while (j > 0 && inp->map[j][i] == ' ')
			j--;
		if (j == 0 && inp->map[j][i] == ' ')
			break ;
		if (inp->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ver_first_check(t_inp_data *inp)
{
	int	j;
	int	i;

	i = 0;
	while (inp->map[0][i + 1])
	{
		j = 0;
		while (inp->map[j][i] == ' ')
			j++;
		if (inp->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ver_border(t_inp_data *inp)
{
	if (ver_first_check(inp) == 1)
		return (1);
	if (ver_last_check(inp) == 1)
		return (1);
	return (0);
}
