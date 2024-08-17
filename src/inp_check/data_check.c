#include "libraries.h"

void	min_line(char *data)
{
	int	i;
	int	line;

	i = 0;
	line = 0;
	while (data[i])
	{
		if (data[i] == '\n')
			line++;
		i++;
	}
	if (line < 8)
	{	
		ft_putstr_fd("Error\nMinimum 8 lines of inp required\n", 2);
		free(data);
		exit(EXIT_FAILURE);	
	}
}

void	data_check(char *data)
{
	min_line(data);
	element_check(data);
	texture_check(data);
}