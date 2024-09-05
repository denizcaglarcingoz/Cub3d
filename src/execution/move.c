#include "libraries.h"

void	w_move(t_all *all)
{
	// Use player move speed instead of hardcoded values
	double	move_step = all->player.move_speed * cos(all->player.rotation_angle * (M_PI / 180)) * 0.3;
	double	new_x = all->player.p_pos_x + move_step;
	double	new_y = all->player.p_pos_y + all->player.move_speed * sin(all->player.rotation_angle * (M_PI / 180)) * 0.3;

	// Check if the new position is not hitting a wall ('1')
	if (all->inp.map[(int)new_y][(int)new_x] != '1')
	{
		all->player.p_pos_x = new_x;
		all->player.p_pos_y = new_y;
	}
}

void	s_move(t_all *all)
{
	double	move_step = all->player.move_speed * cos(all->player.rotation_angle * (M_PI / 180)) * 0.3;
	double	new_x = all->player.p_pos_x - move_step;
	double	new_y = all->player.p_pos_y - all->player.move_speed * sin(all->player.rotation_angle * (M_PI / 180)) * 0.3;

	if (all->inp.map[(int)new_y][(int)new_x] != '1')
	{
		all->player.p_pos_x = new_x;
		all->player.p_pos_y = new_y;
	}
}

void	a_move(t_all *all)
{
	double	move_step = all->player.move_speed * cos((all->player.rotation_angle + 90) * (M_PI / 180)) * 0.3;
	double	new_x = all->player.p_pos_x - move_step;
	double	new_y = all->player.p_pos_y - all->player.move_speed * sin((all->player.rotation_angle + 90) * (M_PI / 180)) * 0.3;

	if (all->inp.map[(int)new_y][(int)new_x] != '1')
	{
		all->player.p_pos_x = new_x;
		all->player.p_pos_y = new_y;
	}
}

void	d_move(t_all *all)
{
	double	move_step = all->player.move_speed * cos((all->player.rotation_angle + 90) * (M_PI / 180)) * 0.3;
	double	new_x = all->player.p_pos_x + move_step;
	double	new_y = all->player.p_pos_y + all->player.move_speed * sin((all->player.rotation_angle + 90) * (M_PI / 180)) * 0.3;

	if (all->inp.map[(int)new_y][(int)new_x] != '1')
	{
		all->player.p_pos_x = new_x;
		all->player.p_pos_y = new_y;
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
