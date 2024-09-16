/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:52:06 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/02 15:57:30 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "libraries.h"
# include "minilibx.h"
# include "inp_data.h"
# include "functions.h"

typedef struct s_ray
{
	double		ray_angle;
	double		ray_angle_radian;
	double		ray_dir_x;
	double		ray_dir_y;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	char		wall_hit_side;
}	t_ray;

typedef struct s_player
{
	double		x;
	double		y;
	double		width;
	double		height;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	double		move_speed;
	double		rotation_speed;
	double		p_pos_x;
	double		p_pos_y;
}	t_player;

typedef struct s_tex
{
	int 	width;
	int 	height;
	void 	*img;
	int 	*data;
	int 	line_length;
} t_tex;


typedef struct s_texture_info {
	int i;
	int wall_height;
	int wall_height2;
	int wall_top;
	int sky;
	int floor;
	double wall_hit_percentage;
	int tex_loc_w;
} t_texture_info;



typedef struct s_all
{
	t_player player;
	t_ray	ray;
	t_mlx	libx;
	t_inp_data	inp;
	t_tex	tex_no;
	t_tex	tex_so;
	t_tex	tex_we;
	t_tex	tex_ea;
} t_all;

#endif