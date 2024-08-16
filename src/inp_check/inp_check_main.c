/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_check_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:57:36 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 18:29:26 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	inp_check_main(char *file_name)
{
	char	*data;

	file_name_check(file_name);
	data = get_file_data(file_name);
	data_check(data);
	// printf("%s\n", data);
}