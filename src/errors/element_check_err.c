#include "libraries.h"

void	element_check_err(char *data, t_inp_data *inp)
{
	free(data);
	inp_data_free(inp);
	ft_putstr_fd("Error\n Element Check Error\n", 2);
	exit(EXIT_FAILURE);
}