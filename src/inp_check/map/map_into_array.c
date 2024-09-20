/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_into_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:26 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:27 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	*map_array_size(char *data, int i, int *size)
{
	int		last_i;

	while (data[i] == '\n')
		(i)++;
	size[0] = 0;
	size[1] = 0;
	last_i = i;
	while (data[i])
	{
		if (data[i] == '\n')
		{
			size[0]++;
			if (size[1] == 0)
				size[1] = i - last_i;
			else
			{
				if (i - last_i > size[1])
					size[1] = i - last_i;
			}
			last_i = i;
		}
		i++;
	}
	size[0]++;
	return (size);
}

void	map_into_array(char *data, int i, t_inp_data *inp)
{
	int		size[2];

	map_array_size(data, i, size);
	map_init(data, size, inp);
	map_data_copy(data, i, inp);
}
