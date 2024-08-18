#include "libraries.h"

void	next_new_line(char *data, int *i)
{
	while (data[*i] != '\n')
		(*i)++;
}

void	element_find(char *data, int *i, t_inp_data *inp)
{
	static int	c_check = 0;
	static int	p_check = 0;

	if ((data[*i] == 'F' || data[*i] == 'C'))
	{	
		color_check(data, i, inp);
		c_check++;
	}
	else if ((data[*i] == 'N' || data[*i] == 'S' ||
			data[*i] == 'W' || data[*i] == 'E'))
	{
		path_check(data, i, inp);
		p_check++;
	}
	else
	{
		printf("Sdata[*i] = %c\n", data[*i]);
		if (c_check != 1 || p_check != 1)
			element_check_err(data, inp);
		if (data[*i] != '1')
			element_check_err(data, inp);
	}
	if (c_check > 1 || p_check > 1)
		element_check_err(data, inp);
	// else if (data[*i] == 'F')
	// 	inp->floor_color = floor_check(data, i, inp);
	// else if (data[*i] == 'C')
	// 	inp->ceiling_color = ceiling_check(data, i, inp);
	// else
	// 	next_new_line(data, i);
}

void	texture_control(char *data, t_inp_data	*inp)
{
	if (inp->no_path == NULL || inp->so_path == NULL || inp->we_path == NULL || inp->ea_path == NULL)
		element_check_err(data, inp);
	if (inp->floor_color_data == NULL || inp->ceiling_color_data == NULL)
		element_check_err(data, inp);
}

void	element_check(char *data)
{
	int			i;
	t_inp_data	inp;

	i = 0;
	inp_to_null(&inp);
	while (data[i])
	{
		if (data[i] == ' ' || data[i] == '\n')
			while (data[i] == ' ' || data[i] == '\n')
				i++;
		element_find(data, &i, &inp);
		if (data[i] == '1')
			break ;
	}
	printf("here\n");
	texture_control(data, &inp);
}