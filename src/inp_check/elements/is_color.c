/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:03:09 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:03:10 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	color_len(char *data, t_inp_data *inp)
{
	int	color_len;

	color_len = ft_strlen(inp->floor_color_data);
	if (color_len < 5 || color_len > 11)
		element_check_err(data, inp, "color error");
	color_len = ft_strlen(inp->ceiling_color_data);
	if (color_len < 5 || color_len > 11)
		element_check_err(data, inp, "color error");
}

void	color_trim(char *data, t_inp_data *inp)
{
	inp->floor_color_data = ft_strtrim(inp->floor_color_data, " ");
	if (inp->floor_color_data == NULL)
		element_check_err(data, inp, "color error");
	inp->ceiling_color_data = ft_strtrim(inp->ceiling_color_data, " ");
	if (inp->ceiling_color_data == NULL)
		element_check_err(data, inp, "color error");
}

void	color_ingredients(char *data, t_inp_data *inp)
{
	int	i;

	i = 0;
	while (inp->floor_color_data[i])
	{
		if (ft_isdigit(inp->floor_color_data[i]) == 0
			&& inp->floor_color_data[i] != ',')
			element_check_err(data, inp, "color error");
		i++;
	}
	i = 0;
	while (inp->ceiling_color_data[i])
	{
		if (ft_isdigit(inp->ceiling_color_data[i]) == 0
			&& inp->ceiling_color_data[i] != ',')
			element_check_err(data, inp, "color error");
		i++;
	}
}
	// 0,0,0 min 
	// 255,255,255 max

void	is_color(char *data, t_inp_data *inp)
{
	color_trim(data, inp);
	color_len(data, inp);
	color_ingredients(data, inp);
	comma_quantity(data, inp);
	color_num_check(data, inp);
}
