#include "libraries.h"

void    map_char_check(char *data, int i, t_inp_data *inp)
{
	int checks;

	checks = 0;
	while (data[i])
	{
		while (data[i] == '\n' || data[i] == ' ')
			(i)++;
		if (data[i] == 0)
			break ;
		if (data[i] != '1' && data[i] != '0' && data[i] != ' ' && data[i] != '\n' &&
			data[i] != 'W' && data[i] != 'E' && data[i] != 'N' && data[i] != 'S')
			checks++;
		(i)++;
	}
	if (checks != 0)
	{
		inp_data_free(inp);
		ft_putstr_fd("Error\nMap Error\n", 2);
		exit(EXIT_FAILURE);
	}	
}

void    map_check_main(char *data, int *i, t_inp_data *inp)
{
	map_char_check(data, *i, inp);
	map_into_array(data, *i, inp);
	// map_wall_check(data, i, inp);
}