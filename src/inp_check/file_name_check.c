#include "libraries.h"

void	file_name_check(char *file_name)
{
	int		i;

	i = 0;
	if (!file_name)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Invalid file name\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (file_name[i])
		i++;
	if (i < 4 || file_name[i - 1] != 'b' || file_name[i - 2] != 'u'
		|| file_name[i - 3] != 'c' || file_name[i - 4] != '.')
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Invalid file name\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
