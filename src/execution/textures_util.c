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

void	init_tex_fail(t_all *all)
{
	if (all->tex_no.data == NULL || all->tex_no.img == NULL)
		clean_exit(all, 1);
	if (all->tex_so.data == NULL || all->tex_so.img == NULL)
		clean_exit(all, 1);
	if (all->tex_ea.data == NULL || all->tex_ea.img == NULL)
		clean_exit(all, 1);
	if (all->tex_we.data == NULL || all->tex_we.img == NULL)
		clean_exit(all, 1);
}

void	init_to_null(t_all *all)
{
	all->tex_no.img = NULL;
	all->tex_no.data = NULL;
	all->tex_so.img = NULL;
	all->tex_so.data = NULL;
	all->tex_ea.img = NULL;
	all->tex_ea.data = NULL;
	all->tex_we.img = NULL;
	all->tex_we.data = NULL;
}

void	init_texture(t_all *all)
{
	init_to_null(all);
	all->tex_no.img = mlx_xpm_file_to_image(all->libx.mlx,
			all->inp.no_path, &all->tex_no.width, &all->tex_no.height);
	all->tex_no.data = (int *)mlx_get_data_addr(all->tex_no.img,
			&all->tex_no.line_length, &all->tex_no.line_length,
			&all->tex_no.line_length);
	all->tex_so.img = mlx_xpm_file_to_image(all->libx.mlx,
			all->inp.so_path, &all->tex_so.width, &all->tex_so.height);
	all->tex_so.data = (int *)mlx_get_data_addr(all->tex_so.img,
			&all->tex_so.line_length, &all->tex_so.line_length,
			&all->tex_so.line_length);
	all->tex_ea.img = mlx_xpm_file_to_image(all->libx.mlx,
			all->inp.ea_path, &all->tex_ea.width, &all->tex_ea.height);
	all->tex_ea.data = (int *)mlx_get_data_addr(all->tex_ea.img,
			&all->tex_ea.line_length, &all->tex_ea.line_length,
			&all->tex_ea.line_length);
	all->tex_we.img = mlx_xpm_file_to_image(all->libx.mlx,
			all->inp.we_path, &all->tex_we.width, &all->tex_we.height);
	all->tex_we.data = (int *)mlx_get_data_addr(all->tex_we.img,
			&all->tex_we.line_length, &all->tex_we.line_length,
			&all->tex_we.line_length);
	init_tex_fail(all);
}
