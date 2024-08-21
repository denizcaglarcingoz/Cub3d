#include "libraries.h"

char	*color_data_get(char *data, int *i)
{
	int		j;
	char	*color;

	*i += 1;
	while (data[*i] == ' ')
		(*i)++;
	j = *i;
	color = NULL;
	while (data[j] != '\n')
		j++;
	if (j == *i)
		return (NULL);
	color = ft_substr(data, *i, j - *i);
	if (color == NULL)
	{
		ft_putstr_fd("Malloc_Error", 2);
		return (NULL);
	}
	*i = j;
	printf("path = '%s'\n", color);
	printf("data[*i] = %c\n", data[*i]);
	return (color);
}

void	color_check(char *data, int *i, t_inp_data *inp)
{
	int	checks[2];

	checks[0] = 0;
	checks[1] = 0;
	while (data[*i])
	{
		while (data[*i] == '\n' || data[*i] == ' ')
			(*i)++;
		if (data[*i] == 'F')
		{
			inp->floor_color_data = color_data_get(data, i);
			checks[0]++;
		}
		else if (data[*i] == 'C')
		{
			inp->ceiling_color_data = color_data_get(data, i);
			checks[1]++;
		}
		else
			break ;
	}
	if (checks[0] != 1 || checks[1] != 1)
		element_check_err(data, inp, "color error");
}
