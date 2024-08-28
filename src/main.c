#include "libraries.h"

//needs fixing
void	mlx_null_free(t_all *all)
{
	ft_putstr_fd("Mlx_Init_Error", 2);
	free(all);
	exit(EXIT_FAILURE);
}

//needs fixing
void img_null_free(t_all *all)
{
	ft_putstr_fd("Mlx_New_Image_Error", 2);
	mlx_destroy_window(all->libx.mlx, all->libx.win);
	free(all);
	exit(EXIT_FAILURE);
}
// needs fixing
void	free_all(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_destroy_window(all->libx.mlx, all->libx.win);
	mlx_destroy_display(all->libx.mlx);
	if (all->libx.mlx)
		free(all->libx.mlx);
	if (all)
		free(all);
	exit(EXIT_FAILURE);
}

static void	mlx_inits(t_all *all)
{
	all->libx.max_iterations = 100;
	all->libx.win_height = 600;
	all->libx.win_witdh = 600;
	all->player.rotation_angle = 0;
	all->player.p_pos_x = all->inp.p_pos_x + 0.5;
	all->player.p_pos_y = all->inp.p_pos_y + 0.5;
	all->libx.mlx = mlx_init();
	all->libx.auto_key = XOpenDisplay(NULL);
	all->libx.w_pressed = 0;
	all->libx.a_pressed = 0;
	all->libx.s_pressed = 0;
	all->libx.d_pressed = 0;
	all->libx.left_pressed = 0;
	all->libx.right_pressed = 0;
	if (all->libx.mlx == NULL)
		mlx_null_free(all); // needs fixing
	all->libx.win = mlx_new_window(all->libx.mlx, all->libx.win_witdh, all->libx.win_height, "Cub3d");
	if (all->libx.win == NULL)
		free_all(all); // needs fixing
	all->libx.img = mlx_new_image(all->libx.mlx, all->libx.win_witdh, all->libx.win_height);
	if (all->libx.img == NULL)
		img_null_free(all); // needs fixing
	exec_main(all);
	mlx_do_key_autorepeaton(all->libx.mlx);
	// mlx_key_hook(all->libx.win, key_hook, all);
	// mlx_loop_hook(all->libx.mlx, key_hook, all);
	mlx_hook(all->libx.win, KeyPress, KeyPressMask, key_press, all);
	// mlx_hook(all->libx.win, ClientMessage, StructureNotifyMask, close_window, all);
	mlx_loop_hook(all->libx.mlx, exec_main, all);
	mlx_hook(all->libx.win, KeyRelease, KeyReleaseMask, key_release, all);
	mlx_loop(all->libx.mlx);
}

int main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		arg_error();
	inp_check_main(argv[1], &(all.inp));
	mlx_inits(&all);

	return (EXIT_SUCCESS);
}