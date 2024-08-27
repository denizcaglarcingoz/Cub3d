/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:52:06 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/27 15:20:16 by dcingoz          ###   ########.fr       */
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

typedef struct s_all
{
	t_player player;
	t_ray	ray;
	t_mlx	libx;
	t_inp_data	inp;
} t_all;

#endif