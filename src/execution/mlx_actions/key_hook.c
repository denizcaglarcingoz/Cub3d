#include "libraries.h"

void	destroy_move(t_all *all)
{
	mlx_destroy_image(all->libx.mlx, all->libx.img);
	mlx_clear_window(all->libx.mlx, all->libx.win);
}

// w = 119
// a = 97			
// s = 115			
// d = 100

void	is_key_pressed(t_all *all)
{
	if (all->libx.w_pressed != 0)
		arrow_move(119, all);
	if (all->libx.a_pressed != 0)
		arrow_move(97, all);
	if (all->libx.s_pressed != 0)
		arrow_move(115, all);
	if (all->libx.d_pressed != 0)
		arrow_move(100, all);
	if (all->libx.left_pressed != 0)
		arrow_move(65361, all);
	if (all->libx.right_pressed != 0)
		arrow_move(65363, all);
}

int	key_press(int key_code, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key_code == 65307)
		clean_exit(all, 0);
	if (key_code == 119)
		all->libx.w_pressed = 119;
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
	return (0);
}

int	key_release(int key_code, void *param)
{
	t_all	*all;

	all = (t_all *)param;
	if (key_code == 65307)
		clean_exit(all, 0);
	if (key_code == 119)
		all->libx.w_pressed = 0;
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
	return (0);
}
