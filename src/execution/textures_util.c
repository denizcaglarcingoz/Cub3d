#include "libraries.h"

void	wall_hit_side(t_all *all, double wall_hit_percentage, int *tex_loc_w)
{
	if (all->ray.wall_hit_side == 'N')
		*tex_loc_w = (int)(wall_hit_percentage * all->tex_no.width);
	else if (all->ray.wall_hit_side == 'S')
		*tex_loc_w = (int)(wall_hit_percentage * all->tex_so.width);
	else if (all->ray.wall_hit_side == 'E')
		*tex_loc_w = (int)(wall_hit_percentage * all->tex_ea.width);
	else if (all->ray.wall_hit_side == 'W')
		*tex_loc_w = (int)(wall_hit_percentage * all->tex_we.width);
}

double	wall_hit_perc(t_all *all)
{
	double	wall_hit_percentage;

	if (all->ray.wall_hit_side == 'N' || all->ray.wall_hit_side == 'S')
		wall_hit_percentage = (all->ray.wall_hit_x - (int)all->ray.wall_hit_x);
	else
		wall_hit_percentage = (all->ray.wall_hit_y - (int)all->ray.wall_hit_y);
	return (wall_hit_percentage);
}

t_texture_info	init_texture_info(t_all *all)
{
	t_texture_info	tex_info;

	tex_info.tex_loc_w = 0;
	tex_info.wall_height = (600 / all->ray.distance);
	tex_info.sky = (600 - tex_info.wall_height) / 2;
	tex_info.floor = 600 - tex_info.wall_height - tex_info.sky;
	tex_info.wall_top = tex_info.sky;
	tex_info.i = 0;
	tex_info.wall_hit_percentage = wall_hit_perc(all);
	wall_hit_side(all, tex_info.wall_hit_percentage, &tex_info.tex_loc_w);
	tex_info.wall_height2 = (600 / all->ray.distance);
	return (tex_info);
}