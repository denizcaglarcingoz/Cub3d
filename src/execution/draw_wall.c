/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:04:07 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:04:08 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"
#include "exec.h"

void	n_draw(t_all *all, int px_loc, t_texture_info info, int *tex_loc_h)
{
	if (*tex_loc_h >= 0 && *tex_loc_h < all->tex_no.height
		&& info.tex_loc_w >= 0 && info.tex_loc_w < all->tex_no.width)
	{
		*tex_loc_h = ((info.i - info.wall_top)
				* all->tex_no.height) / info.wall_height2;
		put_pixel_to_image(all, px_loc, info.i,
			all->tex_no.data[*tex_loc_h * all->tex_no.width + info.tex_loc_w]);
	}
}

void	s_draw(t_all *all, int px_loc, t_texture_info info, int *tex_loc_h)
{
	if (*tex_loc_h >= 0 && *tex_loc_h < all->tex_so.height
		&& info.tex_loc_w >= 0 && info.tex_loc_w < all->tex_so.width)
	{
		*tex_loc_h = ((info.i - info.wall_top)
				* all->tex_so.height) / info.wall_height2;
		put_pixel_to_image(all, px_loc, info.i,
			all->tex_so.data[*tex_loc_h * all->tex_so.width + info.tex_loc_w]);
	}
}

void	e_draw(t_all *all, int px_loc, t_texture_info info, int *tex_loc_h)
{
	if (*tex_loc_h >= 0 && *tex_loc_h < all->tex_ea.height
		&& info.tex_loc_w >= 0 && info.tex_loc_w < all->tex_ea.width)
	{
		*tex_loc_h = ((info.i - info.wall_top)
				* all->tex_ea.height) / info.wall_height2;
		put_pixel_to_image(all, px_loc, info.i,
			all->tex_ea.data[*tex_loc_h * all->tex_ea.width + info.tex_loc_w]);
	}
}

void	w_draw(t_all *all, int px_loc, t_texture_info info, int *tex_loc_h)
{
	if (*tex_loc_h >= 0 && *tex_loc_h < all->tex_we.height
		&& info.tex_loc_w >= 0 && info.tex_loc_w < all->tex_we.width)
	{
		*tex_loc_h = ((info.i - info.wall_top)
				* all->tex_we.height) / info.wall_height2;
		put_pixel_to_image(all, px_loc, info.i,
			all->tex_we.data[*tex_loc_h * all->tex_we.width + info.tex_loc_w]);
	}
}

void	draw_wall(t_all *all, int px_loc, t_texture_info tex_info)
{
	int	tex_loc_h;

	tex_loc_h = 0;
	if (all->ray.wall_hit_side == 'N')
		n_draw(all, px_loc, tex_info, &tex_loc_h);
	else if (all->ray.wall_hit_side == 'S')
		s_draw(all, px_loc, tex_info, &tex_loc_h);
	else if (all->ray.wall_hit_side == 'E')
		e_draw(all, px_loc, tex_info, &tex_loc_h);
	else if (all->ray.wall_hit_side == 'W')
		w_draw(all, px_loc, tex_info, &tex_loc_h);
}
