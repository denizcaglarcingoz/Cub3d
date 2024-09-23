/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:04:00 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:50:24 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	w_move(t_all *all)
{
	if (all->inp.map[(int)(all->player.p_pos_y + ((0.1
					* sin(all->player.rotation_angle
						* (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			+ ((+0.1 * cos(all->player.rotation_angle
				* (M_PI / 180))) * 0.3) * 2)] != '1'
		&& all->inp.map[(int)(all->player.p_pos_y + ((0.1
					* sin(all->player.rotation_angle
						* (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			+ ((+0.1 * cos(all->player.rotation_angle
				* (M_PI / 180))) * 0.3) * 2)] != ' ')
	{
		all->player.p_pos_x += (+0.1
				* cos(all->player.rotation_angle * (M_PI / 180))) * 0.3;
		all->player.p_pos_y += (+0.1
				* sin(all->player.rotation_angle * (M_PI / 180))) * 0.3;
	}
}

void	s_move(t_all *all)
{
	if (all->inp.map[(int)(all->player.p_pos_y - ((0.1
					* sin(all->player.rotation_angle
						* (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			- ((0.1 * cos(all->player.rotation_angle
				* (M_PI / 180))) * 0.3) * 2)] != '1'
		&& all->inp.map[(int)(all->player.p_pos_y - ((0.1
					* sin(all->player.rotation_angle
						* (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			- ((0.1 * cos(all->player.rotation_angle
				* (M_PI / 180))) * 0.3) * 2)] != ' ')
	{
		all->player.p_pos_x -= (0.1
				* cos(all->player.rotation_angle * (M_PI / 180))) * 0.3;
		all->player.p_pos_y -= (0.1
				* sin(all->player.rotation_angle * (M_PI / 180))) * 0.3;
	}
}

void	a_move(t_all *all)
{
	if (all->inp.map[(int)(all->player.p_pos_y - ((0.1
					* sin((all->player.rotation_angle
							+ 90) * (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			- ((0.1 * cos((all->player.rotation_angle
				+ 90) * (M_PI / 180))) * 0.3) * 2)] != '1'
		&& all->inp.map[(int)(all->player.p_pos_y - ((0.1
					* sin((all->player.rotation_angle
							+ 90) * (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x
			- ((0.1 * cos((all->player.rotation_angle
				+ 90) * (M_PI / 180))) * 0.3) * 2)] != ' ')
	{
		all->player.p_pos_y -= (0.1
				* sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
		all->player.p_pos_x -= (0.1
				* cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
	}
}

void	d_move(t_all *all)
{
	if (all->inp.map[(int)(all->player.p_pos_y + ((0.1
					* sin((all->player.rotation_angle
							+ 90) * (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x + ((0.1
			* cos((all->player.rotation_angle
				+ 90) * (M_PI / 180))) * 0.3) * 2)] != '1'
		&& all->inp.map[(int)(all->player.p_pos_y + ((0.1
					* sin((all->player.rotation_angle
							+ 90) * (M_PI / 180))) * 0.3) * 2)]
		[(int)(all->player.p_pos_x + ((0.1
			* cos((all->player.rotation_angle
				+ 90) * (M_PI / 180))) * 0.3) * 2)] != ' ')
	{
		all->player.p_pos_y += (0.1
				* sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
		all->player.p_pos_x += (0.1
				* cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
	}
}

void	arrow_move(int key_code, t_all *all)
{
	if (key_code == 119)
		w_move(all);
	else if (key_code == 115)
		s_move(all);
	else if (key_code == 97)
		a_move(all);
	else if (key_code == 100)
		d_move(all);
	else if (key_code == 65361)
	{
		if (all->player.rotation_angle > 0)
			all->player.rotation_angle -= 0.5;
		else
			all->player.rotation_angle = 360;
	}
	else if (key_code == 65363)
	{
		if (all->player.rotation_angle < 360)
			all->player.rotation_angle += 0.5;
		else
			all->player.rotation_angle = 0;
	}
}
