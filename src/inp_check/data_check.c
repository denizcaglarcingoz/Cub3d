/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:21 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 17:34:37 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	min_line(char *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			line++;
		i++;
	}
	if (line < 8)
	{
		ft_putstr_fd("Error\nMinimum 8 lines of inp required\n", 2);
		free(data);
		exit(EXIT_FAILURE);
	}
}

void	data_check(char *data, t_inp_data *inp)
{
	int	i;

	i = 0;
	min_line(data);
	element_check(data, &i, inp);
	map_check_main(data, &i, inp);
}
