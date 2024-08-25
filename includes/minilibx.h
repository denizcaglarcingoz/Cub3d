/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:08:16 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/25 17:23:58 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "libraries.h"
# include "functions.h"
# include "inp_data.h"
# include "exec.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		max_iterations;
	int		win_witdh;
	int		win_height;
	int		bits_per_pixel;
	int		line_length;
}	t_mlx;

#endif