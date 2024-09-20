/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:56 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:57 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	char_check(t_inp_data *inp)
{
	int	i;
	int	j;
	int	char_loc;

	char_loc = 0;
	i = 0;
	while (inp->map[i])
	{
		j = 0;
		while (inp->map[i][j])
		{
			if (inp->map[i][j] == 'W' || inp->map[i][j] == 'E' ||
				inp->map[i][j] == 'N' || inp->map[i][j] == 'S')
				char_loc++;
			j++;
		}
		i++;
	}
	if (char_loc != 1)
		return (1);
	return (0);
}
