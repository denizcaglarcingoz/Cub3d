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

static void	set_player(t_inp_data *inp,t_all *all, int i, int j)
{
	if (inp->map[i][j] == 'N')
		all->player.rotation_angle = 270;
	else if (inp->map[i][j] == 'S')
		all->player.rotation_angle = 90;
	else if (inp->map[i][j] == 'W')
		all->player.rotation_angle = 180;
	else if (inp->map[i][j] == 'E')
		all->player.rotation_angle = 0;
}

void	set_p_pos(t_inp_data *inp, t_all *all)
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
				set_player(inp, all, i, j);
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
