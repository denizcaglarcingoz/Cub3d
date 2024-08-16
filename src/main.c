/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:48:52 by dcingoz           #+#    #+#             */
/*   Updated: 2024/08/16 18:03:44 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

int main(int argc, char **argv)
{
	t_mlx	libx;

	if (argc != 2)
		arg_error();
	inp_check_main(argv[1]);
	libx.mlx = mlx_init();
	if (libx.mlx == NULL) {
		return (EXIT_FAILURE); // Initialization failed
	}
	libx.win = mlx_new_window(libx.mlx, 800, 600, "My Window");
	if (libx.win == NULL) {
	    free(libx.mlx); // Clean up if window creation fails
	    return (EXIT_FAILURE);
	}
	mlx_loop(libx.mlx);

	return (EXIT_SUCCESS);
}