#include "libraries.h"

void	element_check_err(char *data, t_inp_data *inp, char *msg)
{
	free(data);
	inp_data_free(inp);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
