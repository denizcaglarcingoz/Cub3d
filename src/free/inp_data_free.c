/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_data_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:21:51 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 19:22:11 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	inp_data_free(t_inp_data *inp)
{
	if (inp->no_path)
		free(inp->no_path);
	if (inp->so_path)
		free(inp->so_path);
	if (inp->ea_path)
		free(inp->ea_path);
	if (inp->we_path)
		free(inp->we_path);
	if (inp->sprite_path)
		free(inp->sprite_path);
	if (inp->map)
		free(inp->map);
}