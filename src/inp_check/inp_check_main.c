/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_check_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:10 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 17:34:01 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	inp_check_main(char *file_name, t_inp_data *inp)
{
	char	*data;

	file_name_check(file_name);
	data = get_file_data(file_name);
	if (!data)
		malloc_error();
	data_check(data, inp);
	free(data);
	set_p_pos(inp);
	color_set(inp);
}
