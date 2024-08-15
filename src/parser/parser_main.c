/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:57:36 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/15 19:50:36 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	parser_main(char *file_name)
{
	char	*data;

	file_name_check(file_name);
	data = get_file_data(file_name);
	data_check(data);
	// while (get_next_line(fd, &line) > 0)
	// {
	// 	ft_putstr_fd(line, STDOUT_FILENO);
	// 	ft_putchar_fd('\n', STDOUT_FILENO);
	// 	free(line);
	// }
	// close(fd);
}