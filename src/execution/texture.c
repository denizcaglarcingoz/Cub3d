#include "libraries.h"

void	init_texture(t_all *all)
{
	all->tex_no.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.no_path, &all->tex_no.width, &all->tex_no.height);
	all->tex_no.data = (int *)mlx_get_data_addr(all->tex_no.img, &all->tex_no.line_length, &all->tex_no.line_length, &all->tex_no.line_length);
	if (all->tex_no.data == NULL || all->tex_no.img == NULL)
		clean_exit(all, 1);
	all->tex_so.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.so_path, &all->tex_so.width, &all->tex_so.height);
	all->tex_so.data = (int *)mlx_get_data_addr(all->tex_so.img, &all->tex_so.line_length, &all->tex_so.line_length, &all->tex_so.line_length);
	if (all->tex_so.data == NULL || all->tex_so.img == NULL)
		clean_exit(all, 1);
	all->tex_ea.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.ea_path, &all->tex_ea.width, &all->tex_ea.height);
	all->tex_ea.data = (int *)mlx_get_data_addr(all->tex_ea.img, &all->tex_ea.line_length, &all->tex_ea.line_length, &all->tex_ea.line_length);
	if (all->tex_ea.data == NULL || all->tex_ea.img == NULL)
		clean_exit(all, 1);
	all->tex_we.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.we_path, &all->tex_we.width, &all->tex_we.height);
	all->tex_we.data = (int *)mlx_get_data_addr(all->tex_we.img, &all->tex_we.line_length, &all->tex_we.line_length, &all->tex_we.line_length);
	if (all->tex_we.data == NULL || all->tex_we.img == NULL)
		clean_exit(all, 1);
}

void	init_image(t_all *all) 
{
	all->libx.img = mlx_new_image(all->libx.mlx, all->libx.win_witdh, all->libx.win_height);
	if (all->libx.img == NULL)
		clean_exit(all, 1);
	all->libx.addr = mlx_get_data_addr(all->libx.img, &all->libx.bits_per_pixel,
		&all->libx.line_length, &all->libx.endian);
	if (all->libx.addr == NULL)
		clean_exit(all, 1);
}

static void	put_pixel_to_image(t_all *all, int x, int y, int color) {
	char	*dst;

	dst = all->libx.addr + (y * all->libx.line_length + x * (all->libx.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_texture(t_all *all, int px_loc)
{
	int	i;
	int	wall_height;
	int	wall_height2;
	int	wall_top;
	int	sky;
	int	floor;
	double wall_hit_percentage;
	int tex_loc_w;
	int tex_loc_h;

	tex_loc_h = 0;
	tex_loc_w = 0;
	wall_height = (600 / all->ray.distance);
	sky = (600 - wall_height) / 2;
	floor = 600 - wall_height - sky;
	wall_top = sky;
	i = 0;
	if (all->ray.wall_hit_side == 'N' || all->ray.wall_hit_side == 'S')
		wall_hit_percentage = (all->ray.wall_hit_x - (int)all->ray.wall_hit_x);
	else
		wall_hit_percentage = (all->ray.wall_hit_y - (int)all->ray.wall_hit_y);
	if (all->ray.wall_hit_side == 'N')
		tex_loc_w = (int)(wall_hit_percentage * all->tex_no.width);
	else if (all->ray.wall_hit_side == 'S')
		tex_loc_w = (int)(wall_hit_percentage * all->tex_so.width);
	else if (all->ray.wall_hit_side == 'E')
		tex_loc_w = (int)(wall_hit_percentage * all->tex_ea.width);
	else if (all->ray.wall_hit_side == 'W')
		tex_loc_w = (int)(wall_hit_percentage * all->tex_we.width);
	wall_height2 = (600 / all->ray.distance);
	while (i < all->libx.win_height)
	{
		if (sky > 0) 
		{
			put_pixel_to_image(all, px_loc, i, all->inp.ceiling_color);
			sky--;
		}
		else if (wall_height > 0 && sky <= 0)
		{
			if (all->ray.wall_hit_side == 'N') {
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_no.height && tex_loc_w >= 0 && tex_loc_w < all->tex_no.width) {
					tex_loc_h = ((i - wall_top) * all->tex_no.height) / wall_height2;
					put_pixel_to_image(all, px_loc, i, all->tex_no.data[tex_loc_h * all->tex_no.width + tex_loc_w]);
				}
			} else if (all->ray.wall_hit_side == 'S') {
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_so.height && tex_loc_w >= 0 && tex_loc_w < all->tex_so.width) {
					tex_loc_h = ((i - (wall_top)) * all->tex_so.height) / wall_height2;
					put_pixel_to_image(all, px_loc, i, all->tex_so.data[tex_loc_h * all->tex_so.width + tex_loc_w]);
				}
			} else if (all->ray.wall_hit_side == 'E') {
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_ea.height && tex_loc_w >= 0 && tex_loc_w < all->tex_ea.width) {
					tex_loc_h = ((i - wall_top) * all->tex_ea.height) / wall_height2;
					put_pixel_to_image(all, px_loc, i, all->tex_ea.data[tex_loc_h * all->tex_ea.width + tex_loc_w]);
				}
			} else if (all->ray.wall_hit_side == 'W') {
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_we.height && tex_loc_w >= 0 && tex_loc_w < all->tex_we.width) {
					tex_loc_h = ((i - wall_top) * all->tex_we.height) / wall_height2;
					put_pixel_to_image(all, px_loc, i, all->tex_we.data[tex_loc_h * all->tex_we.width + tex_loc_w]);
				}
			}
			wall_height--;
		} else if (floor > 0 && wall_height <= 0 && sky <= 0) {
			put_pixel_to_image(all, px_loc, i, all->inp.floor_color);
			floor--;
		}
		i++;
	}
}
