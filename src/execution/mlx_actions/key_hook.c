#include "libraries.h"

int	close_window(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_destroy_window(all->libx.mlx, all->libx.win);
	mlx_destroy_display(all->libx.mlx);
	if (all->libx.mlx)
		free(all->libx.mlx);
	if (all)
		free(all);
	exit(0);
	return (0);
}
void	destroy_move(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_clear_window(all->libx.mlx, all->libx.win);
}

static void	arrow_move(int key_code, t_all *all)
{
	if (key_code == 119)
	{
		printf("up arrow\n");
		// destroy_move(all);
		// all->player.rotation_angle += 1;
		// all->player.rotation_angle = fmod(all->player.rotation_angle, 360);
		// all->player.p_pos_y +=  +0.1 * sin(all->player.rotation_angle * (M_PI / 180));
		printf("p_pos_x: %f\n", all->player.p_pos_x);
		printf("map width: %d\n", all->inp.map_width - 2);
		if ((int)all->player.p_pos_x < (int)(all->inp.map_width - 3) && all->player.p_pos_x > 0)
		{
			if (all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x + 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x - 0.5)] != '1')
			{
				all->player.p_pos_x +=  +0.1 * cos(all->player.rotation_angle * (M_PI / 180));
				all->player.p_pos_y +=  +0.1 * sin(all->player.rotation_angle * (M_PI / 180));

				exec_main(all);
			}
		}
	}
	else if (key_code == 115)
	{
		// destroy_move(all);
		// all->player.p_pos_y -=  +0.1 * sin(all->player.rotation_angle * (M_PI / 180));
		// all->player.rotation_angle -= 1;
		if (all->player.p_pos_x > 0 && (int)all->player.p_pos_x < (int)(all->inp.map_width - 3))
		{
		printf("down arrow\n");
			if (all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x - 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x + 0.5)] != '1')
			{
				all->player.p_pos_x -=  0.1 * cos(all->player.rotation_angle * (M_PI / 180));
				all->player.p_pos_y -=  +0.1 * sin(all->player.rotation_angle * (M_PI / 180));
				exec_main(all);
			}
		}
	}
	else if (key_code == 97)
	{
		// destroy_move(all);
		// all->player.rotation_angle -= 1;
		printf("left arrow\n");
		if (all->player.p_pos_x > 0 && (int)all->player.p_pos_x < (int)(all->inp.map_width - 2)
			&& all->player.p_pos_y > 0 && (int)all->player.p_pos_y < (int)(all->inp.map_height - 2))
		{
			if (all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x - 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x + 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y - 0.5)][(int)(all->player.p_pos_x)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y + 0.5)][(int)(all->player.p_pos_x)] != '1')
			{
				all->player.p_pos_y -=  0.1 * cos(all->player.rotation_angle * (M_PI / 180));
				all->player.p_pos_x -=  0.1 * sin(all->player.rotation_angle * (M_PI / 180));
				exec_main(all);
			}
		}
	}
	else if (key_code == 100)
	{
		// destroy_move(all);
		// all->player.rotation_angle += 1;
		printf("right arrow\n");
		printf("p_pos_x: %f\n", all->player.p_pos_x);
		printf("map width -3 : %d\n", all->inp.map_width - 3);
		printf("p_pos_y: %f\n", all->player.p_pos_y + (0.1 * cos(all->player.rotation_angle * (M_PI / 180))));
		printf("map height - 3: %d\n", all->inp.map_height - 3);
		if (all->player.p_pos_x > 0
			&& all->player.p_pos_x < (double)(all->inp.map_width - 2)
			&& all->player.p_pos_y > 0
			&& (double)all->player.p_pos_y  < (double)(all->inp.map_height - 2))
		{
			if (all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x - 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y)][(int)(all->player.p_pos_x + 0.5)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y - 0.5)][(int)(all->player.p_pos_x)] != '1' &&
				all->inp.map[(int)(all->player.p_pos_y + 0.5)][(int)(all->player.p_pos_x)] != '1')
			{
				all->player.p_pos_y +=  +0.1 * cos(all->player.rotation_angle * (M_PI / 180));
				all->player.p_pos_x +=  +0.1 * sin(all->player.rotation_angle * (M_PI / 180));
				exec_main(all);
			}
		}
		if (all->player.p_pos_x >= (double)(all->inp.map_width - 2)
			|| all->player.p_pos_y >= (double)(all->inp.map_height - 2))
		{
			all->player.p_pos_y -= 0.1 * cos(all->player.rotation_angle * (M_PI / 180));
			all->player.p_pos_x -= 0.1 * sin(all->player.rotation_angle * (M_PI / 180));
		}
	}
	else if (key_code == 65361)
	{
		// destroy_move(all);
		// all->move.x += 0.1;
		printf("rotation_angle: %f\n", all->player.rotation_angle);
		if (all->player.rotation_angle > 0)
			all->player.rotation_angle -= 1;
		else
			all->player.rotation_angle = 360;
		exec_main(all);
	}
	else if (key_code == 65363)
	{
		// destroy_move(all);
		printf("rotation_angle: %f\n", all->player.rotation_angle);
		if (all->player.rotation_angle < 360)
			all->player.rotation_angle += 3;
		else
			all->player.rotation_angle = 0; 
		// all->move.x -= 0.1;
		exec_main(all);
	}
}

int	key_hook(int key_code, void *param)
{
	t_all	*all;

	printf("key_code: %d\n", key_code);
	all = (t_all *)param;
	if (key_code == 65307)
		close_window (all);
	if (key_code == 119)
		arrow_move(key_code, all);
	if (key_code == 115)
		arrow_move(key_code, all);
	if (key_code == 97)
		arrow_move(key_code, all);
	if (key_code == 100)
		arrow_move(key_code, all);
	if (key_code == 65361)
		arrow_move(key_code, all);
	if (key_code == 65363)
		arrow_move(key_code, all);
	return (0);
}

// w = 119
// a = 97
// s = 115
// d = 100