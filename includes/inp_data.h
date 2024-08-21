/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:08:33 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/21 23:17:33 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INP_DATA_H
# define INP_DATA_H

# include "libraries.h"
# include "minilibx.h"
# include "functions.h"

typedef struct s_inp_data
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*sprite_path;
	char	*floor_color_data;
	char	*ceiling_color_data;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	int		res_y;
	int		res_x;
}	t_inp_data;

#endif