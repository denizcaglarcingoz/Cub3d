#include "libraries.h"

void	exec_main(t_all *all)
{
	int i;
	double	ray_dir_x;
	double	ray_dir_y;

	all->ray.ray_angle = 45;
	all->ray.ray_angle_radian = all->ray.ray_angle * (M_PI / 180);
	ray_dir_x = cos(all->ray.ray_angle_radian) / 2;
	ray_dir_y = sin(all->ray.ray_angle_radian) / 2;

	printf("ray_dir_x: %f\n", ray_dir_x);
	printf("ray_dir_y: %f\n", ray_dir_y);
	printf("player position x,y : %d, %d\n", all->inp.p_pos_x, all->inp.p_pos_y);
	double p_pos_x = all->inp.p_pos_x + 0.5;
	double p_pos_y = all->inp.p_pos_y + 0.5;
	printf("player position x,y : %f, %f\n", p_pos_x, p_pos_y);
	while (p_pos_x < all->inp.map_width && p_pos_y < all->inp.map_height)
	{
		printf("player position x,y : %f, %f\n", p_pos_x, p_pos_y);
		if (all->inp.map[(int)p_pos_y][(int)p_pos_x] == '1')
		{
			printf("wall hit at x,y : %d, %d\n", (int)p_pos_x, (int)p_pos_y);
			break ;
		}
		p_pos_x += ray_dir_x;
		p_pos_y += ray_dir_y;
	}
	i = 0;
	if (i == 1)
		free(all);
}