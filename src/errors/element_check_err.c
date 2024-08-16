/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_check_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:19:09 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 19:24:32 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

void	element_check_err(char *data, t_inp_data *inp)
{
	free(data);
	inp_data_free(inp);
	ft_putstr_fd("Error\n Element Check Error\n", 2);
	exit(EXIT_FAILURE);
}