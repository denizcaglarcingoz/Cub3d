/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:59:04 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/15 19:00:12 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	file_name_check(char *file_name)
{
	int		i;

	i = 0;
	while (file_name[i])
		i++;
	if (i < 4 || file_name[i - 1] != 'b' || file_name[i - 2] != 'u'
		|| file_name[i - 3] != 'c' || file_name[i - 4] != '.')
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Invalid file name\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}