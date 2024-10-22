/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:32 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:33 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	map_data_copy(char *data, int i, t_inp_data *inp)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (data[i] != '\n')
		i--;
	i++;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			j++;
			k = 0;
			i++;
		}
		if (data[i] == '\0')
			break ;
		inp->map[j][k] = data[i];
		i++;
		k++;
	}
}
