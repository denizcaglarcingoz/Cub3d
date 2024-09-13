#include "libraries.h"

int	color_num_rules(char *color)
{
	int		i;
	int		j;
	char	*num_one;
	char	*num_two;
	char	*num_three;

	i = 0;
	while (color[i] != ',')
		i++;
	num_one = ft_substr(color, 0, i);
	j = i + 1;
	while (color[j] != ',')
		j++;
	num_two = ft_substr(color, i + 1, j - i - 1);
	i = ft_strlen(color);
	num_three = ft_substr(color, j + 1, i - j - 1);
	if (num_one == NULL || num_two == NULL || num_three == NULL)
		return (1);
	if (ft_atoi(num_one) < 0 || ft_atoi(num_one) > 255
		|| ft_atoi(num_two) < 0 || ft_atoi(num_two) > 255
		|| ft_atoi(num_three) < 0 || ft_atoi(num_three) > 255)
		return (1);
	return (0);
}

void	color_num_check(char *data, t_inp_data *inp)
{
	if (color_num_rules(inp->floor_color_data))
		element_check_err(data, inp, "color error");
	if (color_num_rules(inp->ceiling_color_data))
		element_check_err(data, inp, "color error");
}
