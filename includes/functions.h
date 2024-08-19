/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:55:16 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 20:10:30 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libraries.h"
# include "inp_data.h"
# include "minilibx.h"

/* INP CHECK */

void		inp_check_main(char *file_name);
void		file_name_check(char *file_name);
char		*get_file_data(char *file_name);
void		data_check(char *data);
t_inp_data	element_check(char *data, int *i);
void		inp_to_null(t_inp_data *inp);
void		texture_check(char *data);
void		path_check(char *data, int *i, t_inp_data *inp);
void    	color_check(char *data, int *i, t_inp_data *inp);
void		map_check_main(char *data, int *i, t_inp_data *inp);

/* INP DATA FREE */

void		inp_data_free(t_inp_data *inp);

/* Inp Check Errors */

void		arg_error(void);
void		fd_error(void);
void		element_check_err(char *data, t_inp_data *inp);

/* PARSER */




/* EXECUTION */


/* GENERAL ERRORS */
void		malloc_error(void);

#endif