#include "libraries.h"

int	comma_rules(char *color)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (color[0] == ',')
		return (1);
	while (color[i])
	{
		if (color[i] == ',')
		{
			if (color[i + 1] == ',')
				return (1);
			if (color[i - 1] == ',')
				return (1);
			if (color[i + 1] == '\0')
				return (1);
			comma++;
		}
		i++;
	}
	if (comma != 2)
		return (1);
	return (0);
}

void	comma_quantity(char *data, t_inp_data *inp)
{
	if (comma_rules(inp->floor_color_data))
		element_check_err(data, inp, "color error");
	if (comma_rules(inp->ceiling_color_data))
		element_check_err(data, inp, "color error");
}
