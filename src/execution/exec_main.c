#include "libraries.h"

static void	arrow_move(int key_code, t_all *all)
{
	// printf("key_code: %d\n", key_code);
	if (key_code == 119)
	{
		if (all->inp.map[(int)(all->player.p_pos_y + ((+0.1 * cos(all->player.rotation_angle * (M_PI / 180))) * 0.3) * 2)]
			[(int)(all->player.p_pos_x + ((+0.1 * cos(all->player.rotation_angle * (M_PI / 180))) * 0.3) * 2)] != '1')
		{
			all->player.p_pos_x +=  (+0.1 * cos(all->player.rotation_angle * (M_PI / 180))) * 0.3;
			all->player.p_pos_y +=  (+0.1 * sin(all->player.rotation_angle * (M_PI / 180))) * 0.3;
		}
	}
	else if (key_code == 115)
	{
		if (all->inp.map[(int)(all->player.p_pos_y -  ((0.1 * sin(all->player.rotation_angle * (M_PI / 180))) * 0.3) * 2)]
			[(int)(all->player.p_pos_x -  ((0.1 * cos(all->player.rotation_angle * (M_PI / 180))) * 0.3) * 2)] != '1')
		{
			all->player.p_pos_x -=  (0.1 * cos(all->player.rotation_angle * (M_PI / 180))) * 0.3;
			all->player.p_pos_y -=  (0.1 * sin(all->player.rotation_angle * (M_PI / 180))) * 0.3;
		}
	}
	else if (key_code == 97)
	{
		if (all->inp.map[(int)(all->player.p_pos_y -  ((0.1 * sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3) * 2)]
			[(int)(all->player.p_pos_x -  ((0.1 * cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3) * 2)] != '1')
		{
			all->player.p_pos_y -=  (0.1 * sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
			all->player.p_pos_x -=  (0.1 * cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
		}
	}
	else if (key_code == 100)
	{
		// destroy_move(all);
		if (all->inp.map[(int)(all->player.p_pos_y +  ((+0.1 * sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3) * 2)]
			[(int)(all->player.p_pos_x +  ((+0.1 * cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3) * 2)] != '1')
		{
			all->player.p_pos_y +=  (+0.1 * sin((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
			all->player.p_pos_x +=  (+0.1 * cos((all->player.rotation_angle + 90) * (M_PI / 180))) * 0.3;
		}
	}
	else if (key_code == 65361)
	{
		// destroy_move(all);
		if (all->player.rotation_angle > 0)
			all->player.rotation_angle -= 0.3;
		else
			all->player.rotation_angle = 360;
	}
	else if (key_code == 65363)
	{
		// destroy_move(all);
		if (all->player.rotation_angle < 360)
			all->player.rotation_angle += 0.3;
		else
			all->player.rotation_angle = 0; 
	}
}

void	get_wall_side(t_all *all)
{
	double x;
	double y;

	x = (int)(all->ray.wall_hit_x - all->ray.ray_dir_x);
	y = (int)(all->ray.wall_hit_y - all->ray.ray_dir_y); 
	if (x == (int)all->ray.wall_hit_x)
	{
		if (all->ray.ray_angle_radian > 0 && all->ray.ray_angle_radian < M_PI)
			all->ray.wall_hit_side = 'N';
		else
			all->ray.wall_hit_side = 'S';
	}
	else
	{
		if (all->ray.ray_angle_radian > M_PI / 2 && all->ray.ray_angle_radian < 3 * M_PI / 2)
			all->ray.wall_hit_side = 'E';
		else
			all->ray.wall_hit_side = 'W';
	}
}

void	get_distance(t_all *all, double p_pos_x, double p_pos_y)
{

	all->ray.distance = sqrt(pow(p_pos_x - all->ray.wall_hit_x, 2) + pow(p_pos_y - all->ray.wall_hit_y, 2));
	all->ray.distance *= cos((all->ray.ray_angle_radian - (all->player.rotation_angle * (M_PI / 180))));
}

void	put_pixel(t_all *all, int pixel_loc)
{
	int i;
	int wall;
	int sky;
	int floor;

	wall = (600 / all->ray.distance);
	sky = (600 - wall) / 2;
	floor = 600 - wall - sky;
	i = 0;
	while (i < all->libx.win_height)
	{
		if (sky > 0)
		{
			mlx_pixel_put(all->libx.mlx, all->libx.win, pixel_loc, i, 0x0000FF00);
			sky--;
		}
		else if (wall > 0 && sky <= 0)
		{
			mlx_pixel_put(all->libx.mlx, all->libx.win, pixel_loc, i, 0x00FFFFFF);
			wall--;
		}
		else if (floor > 0 && wall <= 0 && sky <= 0)
		{
			mlx_pixel_put(all->libx.mlx, all->libx.win, pixel_loc, i, 0x00FF0000);
			floor--;
		}
		i++;
	}
}



void	exec_lopp(t_all *all, int pixel_loc)
{

	all->ray.ray_angle_radian = all->ray.ray_angle * (M_PI / 180);

	all->ray.ray_dir_x = cos(all->ray.ray_angle_radian) / 200;
	all->ray.ray_dir_y = sin(all->ray.ray_angle_radian) / 200;
	
	all->ray.wall_hit_x = all->player.p_pos_x;
	all->ray.wall_hit_y = all->player.p_pos_y;
	
	while (all->ray.wall_hit_x < all->inp.map_width && all->ray.wall_hit_y< all->inp.map_height)
	{
		if (all->inp.map[(int)all->ray.wall_hit_y][(int)all->ray.wall_hit_x] == '1')
		{
			get_wall_side(all);
			break ;
		}
		all->ray.wall_hit_x += all->ray.ray_dir_x;
		all->ray.wall_hit_y += all->ray.ray_dir_y;
	}
	get_distance(all, all->player.p_pos_x, all->player.p_pos_y);

	put_pixel(all, pixel_loc);
}
int	exec_main(t_all *all)
{
	int		i;
	double	fov;
	double	ray_increment;

	i = 0;
	fov = 60;

	if (all->libx.w_pressed != 0)
		arrow_move(119, all);
	if (all->libx.a_pressed != 0)
		arrow_move(97, all);
	if (all->libx.s_pressed != 0)
		arrow_move(115, all);
	if (all->libx.d_pressed != 0)
		arrow_move(100, all);
	if (all->libx.left_pressed != 0)
		arrow_move(65361, all);
	if (all->libx.right_pressed != 0)
		arrow_move(65363, all);
	ray_increment = fov / all->libx.win_witdh;
	all->ray.ray_angle = all->player.rotation_angle - (fov / 2);
	while (i < all->libx.win_witdh)
	{
		exec_lopp(all, i);
		all->ray.ray_angle += ray_increment;
		i++;
	}
	return (0);
}