/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:52:06 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/25 20:35:59 by dcingoz          ###   ########.fr       */
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
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	int			was_hit_vertical;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
	int			wall_hit_content;
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
}	t_player;

typedef struct s_all
{
	t_player player;
	t_ray	ray;
	t_mlx	libx;
	t_inp_data	inp;
} t_all;

#endif