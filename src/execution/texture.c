#include "libraries.h"

void	init_texture(t_all *all)
{
	all->tex_no.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.no_path, &all->tex_no.width, &all->tex_no.height);
	all->tex_no.data = (int *)mlx_get_data_addr(all->tex_no.img, &all->tex_no.line_length, &all->tex_no.line_length, &all->tex_no.line_length);
	all->tex_so.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.so_path, &all->tex_so.width, &all->tex_so.height);
	all->tex_so.data = (int *)mlx_get_data_addr(all->tex_so.img, &all->tex_so.line_length, &all->tex_so.line_length, &all->tex_so.line_length);
	all->tex_ea.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.ea_path, &all->tex_ea.width, &all->tex_ea.height);
	all->tex_ea.data = (int *)mlx_get_data_addr(all->tex_ea.img, &all->tex_ea.line_length, &all->tex_ea.line_length, &all->tex_ea.line_length);
	all->tex_we.img = mlx_xpm_file_to_image(all->libx.mlx, all->inp.we_path, &all->tex_we.width, &all->tex_we.height);
	all->tex_we.data = (int *)mlx_get_data_addr(all->tex_we.img, &all->tex_we.line_length, &all->tex_we.line_length, &all->tex_we.line_length);
}

void	put_texture(t_all *all, int px_loc)
{
	int i;
	int wall_height;
	int	wall_height2;
	int	wall_top;
	int sky;
	int floor;


	wall_height = (600 / all->ray.distance);
	sky = (600 - wall_height) / 2;
	floor = 600 - wall_height - sky;
	wall_top = sky;
	i = 0;
	double wall_hit_percentage;
	if (all->ray.wall_hit_side == 'N' || all->ray.wall_hit_side == 'S')
		wall_hit_percentage = (all->ray.wall_hit_x - (int)all->ray.wall_hit_x);
	else
		wall_hit_percentage = (all->ray.wall_hit_y - (int)all->ray.wall_hit_y);
	int tex_loc_w = 0;
	if (all->ray.wall_hit_side == 'N')
		tex_loc_w = (int)(wall_hit_percentage * all->tex_no.width);
	else if (all->ray.wall_hit_side == 'S')
		tex_loc_w =  (int)(wall_hit_percentage * all->tex_so.width);
	else if (all->ray.wall_hit_side == 'E')
		tex_loc_w =  (int)(wall_hit_percentage * all->tex_ea.width);
	else if (all->ray.wall_hit_side == 'W')
		tex_loc_w = (int)( wall_hit_percentage * all->tex_we.width);
	int	tex_loc_h;
	tex_loc_h = 0;
	wall_height2 = (600 / all->ray.distance);
	while (i < all->libx.win_height)
	{
		
		if (sky > 0)
		{
			mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, 0x0000FF00);
			sky--;
		}
		else if (wall_height > 0 && sky <= 0)
		{
			if (all->ray.wall_hit_side == 'N')
			{
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_no.height && tex_loc_w >= 0 && tex_loc_w < all->tex_no.width) 
				{	
					tex_loc_h = ((i - wall_top) * all->tex_no.height) / wall_height2;
					mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, all->tex_no.data[tex_loc_h * all->tex_no.width + tex_loc_w]);
				}
			}

			else if (all->ray.wall_hit_side == 'S')
			{	
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_so.height && tex_loc_w >= 0 && tex_loc_w < all->tex_so.width)
				{
					tex_loc_h = ((i - (wall_top)) * all->tex_so.height) / wall_height2;
					mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, all->tex_so.data[tex_loc_h * all->tex_so.width + tex_loc_w]);
				} 
			}
			else if (all->ray.wall_hit_side == 'E')
			{
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_ea.height && tex_loc_w >= 0 && tex_loc_w < all->tex_ea.width) {
					tex_loc_h = ((i - wall_top) * all->tex_ea.height) / wall_height2;
					mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, all->tex_ea.data[tex_loc_h * all->tex_ea.width + tex_loc_w]);
				}
			}
			else if (all->ray.wall_hit_side == 'W')
			{
				if (tex_loc_h >= 0 && tex_loc_h < all->tex_we.height && tex_loc_w >= 0 && tex_loc_w < all->tex_we.width)
				{
					tex_loc_h = ((i - wall_top) * all->tex_we.height) / wall_height2;
					mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, all->tex_we.data[tex_loc_h * all->tex_we.width + tex_loc_w]);
				}
			}
			wall_height--;
		}
		else if (floor > 0 && wall_height <= 0 && sky <= 0)
		{
			mlx_pixel_put(all->libx.mlx, all->libx.win, px_loc, i, 0x00FF0000);
			floor--;
		}
		i++;
	}
}