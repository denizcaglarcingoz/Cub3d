/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:23 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:05:48 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	color_limit(int red, int green, int blue)
{
	if (red < 0 || red > 255 || green < 0
		|| green > 255 || blue < 0 || blue > 255)
		return (1);
	return (0);
}

void	color_free(char **color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		free(color[i]);
		i++;
	}
	free(color);
}

void	get_color(t_inp_data *inp)
{
	char	**color;
	int		red;
	int		green;
	int		blue;

	color = ft_split(inp->ceiling_color_data, ',');
	if (color == NULL)
		inp_data_free(inp);
	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if (color_limit(red, green, blue))
		(color_free(color), inp_data_free(inp));
	inp->ceiling_color = (red << 16 | green << 8 | blue);
	color_free(color);
	color = ft_split(inp->floor_color_data, ',');
	if (color == NULL)
		inp_data_free(inp);
	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if (color_limit(red, green, blue))
		(color_free(color), inp_data_free(inp));
	inp->floor_color = (red << 16 | green << 8 | blue);
	color_free(color);
}

void	color_set(t_inp_data *inp)
{
	inp->ceiling_color_data = ft_strtrim(inp->ceiling_color_data, " ");
	inp->floor_color_data = ft_strtrim(inp->floor_color_data, " ");
	if (inp->ceiling_color_data == NULL || inp->floor_color_data == NULL)
		inp_data_free(inp);
	inp->ceiling_color = 0;
	inp->floor_color = 0;
	get_color(inp);
}
