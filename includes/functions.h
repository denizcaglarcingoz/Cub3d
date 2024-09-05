/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:55:16 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/02 16:36:13 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "libraries.h"
# include "exec.h"
# include "inp_data.h"
# include "minilibx.h"

typedef struct s_all t_all;

/* INP CHECK */

void		inp_check_main(char *file_name, t_inp_data *inp);
void		file_name_check(char *file_name);
char		*get_file_data(char *file_name);
void		data_check(char *data, t_inp_data *inp);
void		element_check(char *data, int *i, t_inp_data *inp);
void		inp_to_null(t_inp_data *inp);
void		is_color(char *data, t_inp_data *inp);
void		is_element(char *data, t_inp_data *inp);
void		color_num_check(char *data, t_inp_data *inp);
void		comma_quantity(char *data, t_inp_data *inp);
void		does_file_exist(char *data, t_inp_data *inp);
void		is_xpm(char *data, t_inp_data *inp);
void		texture_check(char *data);
void		path_check(char *data, int *i, t_inp_data *inp);
void		color_check(char *data, int *i, t_inp_data *inp);
void		map_check_main(char *data, int *i, t_inp_data *inp);
void		map_into_array(char *data, int i, t_inp_data *inp);
void		map_init(char *data, int *size, t_inp_data *inp);
void		map_data_copy(char *data, int i, t_inp_data *inp);
int			map_wall_check(t_inp_data *inp);
int			hor_border(t_inp_data *inp);
int			ver_border(t_inp_data *inp);
int			char_check(t_inp_data *inp);
int			hor_check(char **map);
int			ver_check(char **map);
void		set_p_pos(t_inp_data *inp);

/* INP DATA FREE */

void		inp_data_free(t_inp_data *inp);

/* Inp Check Errors */

void		arg_error(void);
void		fd_error(void);
void		element_check_err(char *data, t_inp_data *inp, char *msg);

/* PARSER */

/* EXECUTION */

int		exec_main(t_all *inp);
void	is_key_pressed(t_all *all);

void	init_texture(t_all *all);
void    init_image(t_all *all);
void	put_texture(t_all *all, int px_loc);

/* MLX ACTIONS */

int			key_press(int key_code, void *param);
int			key_release(int key_code, void *param);
int			close_window(t_all *all);
void		arrow_move(int key_code, t_all *all);

/* GENERAL ERRORS */
void		malloc_error(void);
void	    clean_exit(t_all *data, int checker);
int         ft_exit(t_all *data);

/* TESTS */
void		print_d_str(char **data);

#endif