#include "libraries.h"

void	malloc_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Failed to allocate memory\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
