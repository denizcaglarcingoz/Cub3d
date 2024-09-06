#include "libraries.h"

void	init_image(t_all *all)
{
	if (all->libx.img)
		(mlx_destroy_image(all->libx.mlx, all->libx.img), all->libx.img = NULL);
	all->libx.img = mlx_new_image(all->libx.mlx,
			all->libx.win_witdh, all->libx.win_height);
	if (all->libx.img == NULL)
		clean_exit(all, 1);
	all->libx.addr = mlx_get_data_addr(all->libx.img, &all->libx.bits_per_pixel,
			&all->libx.line_length, &all->libx.endian);
	if (all->libx.addr == NULL)
		clean_exit(all, 1);
}

void	put_pixel_to_image(t_all *all, int x, int y, int color)
{
	char	*dst;

	dst = all->libx.addr + (y * all->libx.line_length
			+ x * (all->libx.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

void	put_texture(t_all *all, int px_loc)
{
	t_texture_info	tex_info;

	tex_info = init_texture_info(all);
	while (tex_info.i < all->libx.win_height)
	{
		if (tex_info.sky > 0)
		{
			put_pixel_to_image(all, px_loc, tex_info.i, all->inp.ceiling_color);
			tex_info.sky--;
		}
		else if (tex_info.wall_height > 0 && tex_info.sky <= 0)
		{
			draw_wall(all, px_loc, tex_info);
			tex_info.wall_height--;
		}
		else if (tex_info.floor > 0
			&& tex_info.wall_height <= 0 && tex_info.sky <= 0)
		{
			put_pixel_to_image(all, px_loc, tex_info.i, all->inp.floor_color);
			tex_info.floor--;
		}
		tex_info.i++;
	}
}
