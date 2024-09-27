/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:48 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/27 19:25:59 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	map_wall_check(t_inp_data *inp)
{
	if (char_check(inp) == 1)
		return (1);
	if (hor_border(inp) == 1)
		return (1);
	if (ver_border(inp) == 1)
		return (1);
	if (hor_check(inp->map) == 1)
		return (1);
	if (ver_check(inp->map) == 1)
		return (1);
	return (0);
}
