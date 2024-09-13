/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:08:33 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/13 17:22:00 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INP_DATA_H
# define INP_DATA_H

# include "libraries.h"
# include "minilibx.h"
# include "exec.h"
# include "functions.h"

typedef struct s_inp_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*floor_color_data;
	char	*ceiling_color_data;
	unsigned int		floor_color;
	unsigned int		ceiling_color;
	char	**map;
	int		p_pos_x;
	int		p_pos_y;
	int		map_height;
	int		map_width;
}	t_inp_data;

#endif