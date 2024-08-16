/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_to_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:09:57 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 19:10:07 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	inp_to_null(t_inp_data *inp)
{
	inp->no_path = NULL;
	inp->so_path = NULL;
	inp->ea_path = NULL;
	inp->we_path = NULL;
	inp->sprite_path = NULL;
	inp->floor_color = -1;
	inp->ceiling_color = -1;
	inp->map = NULL;
	inp->res_y = -1;
	inp->res_x = -1;
}