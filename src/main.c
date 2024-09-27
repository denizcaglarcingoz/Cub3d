/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:01:37 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/27 17:07:27 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

static void	init_data(t_all *all)
{
	all->libx.max_iterations = 100;
	all->libx.win_height = 600;
	all->libx.win_witdh = 600;
	all->player.p_pos_x = all->inp.p_pos_x + 0.5;
	all->player.p_pos_y = all->inp.p_pos_y + 0.5;
	all->libx.auto_key = XOpenDisplay(NULL);
	all->libx.w_pressed = 0;
	all->libx.a_pressed = 0;
	all->libx.s_pressed = 0;
	all->libx.d_pressed = 0;
	all->libx.left_pressed = 0;
	all->libx.right_pressed = 0;
}

static void	mlx_inits(t_all *all)
{
	init_data(all);
	all->libx.mlx = mlx_init();
	if (all->libx.mlx == NULL)
		clean_exit(all, 1);
	all->libx.win = mlx_new_window(all->libx.mlx,
			all->libx.win_witdh, all->libx.win_height, "Cub3d");
	if (all->libx.win == NULL)
		clean_exit(all, 1);
	all->libx.img = mlx_new_image(all->libx.mlx,
			all->libx.win_witdh, all->libx.win_height);
	if (all->libx.img == NULL)
		clean_exit(all, 1);
	init_image(all);
	init_texture(all);
	exec_main(all);
	mlx_do_key_autorepeaton(all->libx.mlx);
	mlx_hook(all->libx.win, KeyPress, KeyPressMask, key_press, all);
	mlx_hook(all->libx.win, 33, 1L << 17, ft_exit, all);
	mlx_loop_hook(all->libx.mlx, exec_main, all);
	mlx_hook(all->libx.win, KeyRelease, KeyReleaseMask, key_release, all);
	mlx_loop(all->libx.mlx);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		arg_error();
	inp_check_main(argv[1], &(all.inp), &all);
	mlx_inits(&all);
	return (EXIT_SUCCESS);
}
