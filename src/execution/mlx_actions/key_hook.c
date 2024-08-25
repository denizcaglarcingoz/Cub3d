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

static void	arrow_move(int key_code, t_all *all)
{
	if (key_code == 65362)
	{
		destroy_move(all);
		// all->move.y += 0.1;
		exec_main(all);
	}
	else if (key_code == 65364)
	{
		destroy_move(all);
		// all->move.y -= 0.1;
		exec_main(all);
	}
	else if (key_code == 65361)
	{
		destroy_move(all);
		// all->move.x += 0.1;
		exec_main(all);
	}
	else if (key_code == 65363)
	{
		destroy_move(all);
		// all->move.x -= 0.1;
		exec_main(all);
	}
}

int	key_hook(int key_code, void *param)
{
	t_all	*all;

	printf("key_code: %d\n", key_code);
	all = (t_all *)param;
	if (key_code == 65307)
		close_window (all);
	if (key_code == 65362)
		arrow_move(key_code, all);
	if (key_code == 65364)
		arrow_move(key_code, all);
	if (key_code == 65361)
		arrow_move(key_code, all);
	if (key_code == 65363)
		arrow_move(key_code, all);
	return (0);
}

// w = 119
// a = 97
// s = 115
// d = 100