#include "libraries.h"

void	fd_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Failed to open file\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}