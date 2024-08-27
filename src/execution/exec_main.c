#include "libraries.h"

void	get_wall_side(t_all *all)
{
	double x;
	double y;
	// x = p_pos_x - (int)p_pos_x;
	// y = p_pos_y - (int)p_pos_y;
	// x_plus = ((int)p_pos_x + 1) - p_pos_x;
	// y_plus = ((int)p_pos_y + 1) - p_pos_y;
	// if (x_plus < x)
	// 	x = x_plus;
	// if (y_plus < y)
	// 	y = y_plus;
	// printf("x: %f\n", x);
	// printf("y: %f\n", y);
	x = (int)(all->ray.wall_hit_x - all->ray.ray_dir_x);
	y = (int)(all->ray.wall_hit_y - all->ray.ray_dir_y); 
	// printf("y: %f\n", y);
	// printf("x: %f\n", x);
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

	// printf("wall side: %c\n", all->ray.wall_hit_side);
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

	printf("distance: %f\n", all->ray.distance);
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
void	exec_main(t_all *all)
{
	int		i;
	double	fov;
	double	ray_increment;

	i = 0;
	fov = 60;

	ray_increment = fov / all->libx.win_witdh;
	// all->player.rotation_angle = 180;
	all->ray.ray_angle = all->player.rotation_angle - (fov / 2);
	printf("rotation_angle: %f\n", all->player.rotation_angle);
	printf("ray_angle: %f\n", all->ray.ray_angle);
	while (i < all->libx.win_witdh)
	{
		exec_lopp(all, i);
		all->ray.ray_angle += ray_increment;
		i++;
	}
}