#include "libraries.h"

int	close_window(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_destroy_window(all->libx.mlx, all->libx.win);
	mlx_destroy_display(all->libx.mlx);
	if (all->libx.mlx)
		free(all->libx.mlx);
	if (all)
		free(all);
	exit(0);
	return (0);
}
void	destroy_move(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_clear_window(all->libx.mlx, all->libx.win);
}



// int	key_hook(int key_code, void *param)
// {
// 	t_all	*all;

// 	// printf("key_code: %d\n", key_code);
// 	all = (t_all *)param;
// 	if (key_code == 65307)
// 		close_window (all);
// 	if (key_code == 119)
// 		arrow_move(key_code, all);
// 	if (key_code == 115)
// 		arrow_move(key_code, all);
// 	if (key_code == 97)
// 		arrow_move(key_code, all);
// 	if (key_code == 100)
// 		arrow_move(key_code, all);
// 	if (key_code == 65361)
// 		arrow_move(key_code, all);
// 	if (key_code == 65363)
// 		arrow_move(key_code, all);
// 	return (0);
// }

// w = 119
// a = 97
// s = 115
// d = 100


int	key_press(int key_code, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key_code == 65307)
		close_window (all);
	if (key_code == 119)
		all->libx.w_pressed  = 119;
	if (key_code == 97)
		all->libx.a_pressed = 97;
	if (key_code == 115)
		all->libx.s_pressed = 115;
	if (key_code == 100)
		all->libx.d_pressed = 100;
	if (key_code == 65361)
		all->libx.left_pressed = 65361;
	if (key_code == 65363)
		all->libx.right_pressed = 65363;
	return 	(0);
}

int	key_release(int key_code, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key_code == 65307)
		close_window (all);
	if (key_code == 119)
		all->libx.w_pressed  = 0;
	if (key_code == 97)
		all->libx.a_pressed = 0;
	if (key_code == 115)
		all->libx.s_pressed = 0;
	if (key_code == 100)
		all->libx.d_pressed = 0;
	if (key_code == 65361)
		all->libx.left_pressed = 0;
	if (key_code == 65363)
		all->libx.right_pressed = 0;
	return 	(0);
}