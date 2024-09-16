#include "libraries.h"

void	print_d_str(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		printf("array[%d] =		", i);
		printf("'%s'", data[i]);
		printf("\n");
		i++;
	}
}
