/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:03:12 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 17:35:57 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	next_new_line(char *data, int *i)
{
	while (data[*i] != '\n')
		(*i)++;
}

void	element_find(char *data, int *i, t_inp_data *inp)
{
	static int	c_check = 0;
	static int	p_check = 0;

	if ((data[*i] == 'F' || data[*i] == 'C'))
	{
		color_check(data, i, inp);
		c_check++;
	}
	else if ((data[*i] == 'N' || data[*i] == 'S'
			|| data[*i] == 'W' || data[*i] == 'E'))
	{
		path_check(data, i, inp);
		p_check++;
	}
	else
	{
		if (c_check != 1 || p_check != 1)
			element_check_err(data, inp, "element error");
		if (data[*i] != '1')
			element_check_err(data, inp, "element error");
	}
	if (c_check > 1 || p_check > 1)
		element_check_err(data, inp, "element error");
}

void	init_control(char *data, t_inp_data	*inp)
{
	if (inp->no_path == NULL || inp->so_path == NULL
		|| inp->we_path == NULL || inp->ea_path == NULL)
		element_check_err(data, inp, "path null");
	if (inp->floor_color_data == NULL || inp->ceiling_color_data == NULL)
		element_check_err(data, inp, "color null");
}

void	element_check(char *data, int *i, t_inp_data *inp)
{
	inp_to_null(inp);
	while (data[*i])
	{
		if (data[*i] == ' ' || data[*i] == '\n')
			while (data[*i] == ' ' || data[*i] == '\n')
				(*i)++;
		element_find(data, i, inp);
		if (data[*i] == '1')
			break ;
	}
	init_control(data, inp);
	is_element(data, inp);
	is_color(data, inp);
}
