/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:55:16 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/15 19:38:31 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libraries.h"


/* PARSER */

void	parser_main(char *file_name);
void	file_name_check(char *file_name);
char	*get_file_data(char *file_name);

/* ERRORS */

void	arg_error(void);
void	fd_error(void);
void	malloc_error(void);

#endif