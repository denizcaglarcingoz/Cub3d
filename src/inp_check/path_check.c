
#include "libraries.h"

char	*get_path(char *data, int *i)
{
	int		j;
	char	*path;

	j = *i;
	path = NULL;
	while (data[j] != '\n')
		j++;
	if (j == *i)
		return (NULL);
	path = ft_substr(data, i, j - *i);
	if (path == NULL)
	{
		ft_putstr_fd("Malloc_Error", 2);
		return (NULL);
	}
	*i = j;
	return (path);
}




char	*path_check(char *data, int *i, t_inp_data *inp)
{
	int checks[4];

	checks[0] = 0;
	checks[1] = 0;
	checks[2] = 0;
	checks[3] = 0;
	while (data[*i])
	{
		if (data[*i] == 'N' && data[*i + 1] == 'O')
			(inp->no_path = get_path(data, i), checks[0]++);
		else if (data[*i] == 'S' && data[*i + 1] == 'O')
			(inp->so_path = get_path(data, i), checks[1]++);
		else if (data[*i] == 'W' && data[*i + 1] == 'E')
			(inp->we_path = get_path(data, i), checks[2]++);
		else if (data[*i] == 'E' && data[*i + 1] == 'A')
			(inp->ea_path = get_path(data, i), checks[3]++);
		while (data[*i] == '\n' || data[*i] == ' ')
			(*i)++;
	}
	if (checks[0] != 1 || checks[1] != 1 || checks[2] != 1 || checks[3] != 1)
		element_check_err(data, inp);
}
