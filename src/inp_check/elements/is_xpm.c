/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_xpm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:03:04 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:03:05 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int	xpm_rules(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i < 5)
		return (1);
	i--;
	if (path[i] == 'm' && path[i - 1] == 'p'
		&& path[i - 2] == 'x' && path[i - 3] == '.')
		return (0);
	return (1);
}

void	is_xpm(char *data, t_inp_data *inp)
{
	if (xpm_rules(inp->no_path) == 1)
		element_check_err(data, inp, "not xpm file");
	if (xpm_rules(inp->so_path) == 1)
		element_check_err(data, inp, "not xpm file");
	if (xpm_rules(inp->we_path) == 1)
		element_check_err(data, inp, "not xpm file");
	if (xpm_rules(inp->ea_path) == 1)
		element_check_err(data, inp, "not xpm file");
}
