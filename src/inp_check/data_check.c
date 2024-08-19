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
	int	i;
	t_inp_data	inp;

	i = 0;
	min_line(data);
	inp = element_check(data, &i);
	printf("i = %d\n", i);
	map_check_main(data, &i, &inp);
}
