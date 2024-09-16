#include "libraries.h"

int	color_limit(int red, int green, int blue)
{
	if (red < 0 || red > 255 || green < 0
		|| green > 255 || blue < 0 || blue > 255)
		return (1);
	return (0);
}

void	get_color(t_inp_data *inp)
{
	char	**color;
	int		red;
	int		green;
	int		blue;

	color = ft_split(inp->ceiling_color_data, ',');
	if (color == NULL)
		inp_data_free(inp);
	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if (color_limit(red, green, blue))
		inp_data_free(inp);
	inp->ceiling_color = (red << 16 | green << 8 | blue);
	free_split(color);
	color = ft_split(inp->floor_color_data, ',');
	if (color == NULL)
		inp_data_free(inp);
	red = ft_atoi(color[0]);
	green = ft_atoi(color[1]);
	blue = ft_atoi(color[2]);
	if (color_limit(red, green, blue))
		inp_data_free(inp);
	inp->floor_color = (red << 16 | green << 8 | blue);
	free_split(color);
}

void	color_set(t_inp_data *inp)
{
	char	*temp1;
	char	*temp2;

	temp1 = ft_strtrim(inp->ceiling_color_data, " ");
	temp2 = ft_strtrim(inp->floor_color_data, " ");
	free(inp->ceiling_color_data);
	free(inp->floor_color_data);
	inp->ceiling_color_data = temp1;
	inp->floor_color_data = temp2;
	if (inp->ceiling_color_data == NULL || inp->floor_color_data == NULL)
		inp_data_free(inp);
	inp->ceiling_color = 0;
	inp->floor_color = 0;
	get_color(inp);
}
