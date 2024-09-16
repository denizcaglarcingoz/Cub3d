#include "libraries.h"

void	arg_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Invalid arguments\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
