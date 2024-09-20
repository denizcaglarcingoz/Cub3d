/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_p_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:00 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:01 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	set_p_pos(t_inp_data *inp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (inp->map[i])
	{
		while (inp->map[i][j])
		{
			if (inp->map[i][j] == 'N' || inp->map[i][j] == 'S'
				|| inp->map[i][j] == 'W' || inp->map[i][j] == 'E')
			{
				inp->p_pos_x = j;
				inp->p_pos_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
