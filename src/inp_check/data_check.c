/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:50:57 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 18:08:53 by dcingoz          ###   ########.fr       */
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

void	data_check(char *data)
{
	min_line(data);
	texture_check(data);
}