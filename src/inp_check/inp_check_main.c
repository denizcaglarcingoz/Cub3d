
#include "libraries.h"

void	inp_check_main(char *file_name)
{
	char	*data;

	file_name_check(file_name);
	data = get_file_data(file_name);
	data_check(data);
	// printf("%s\n", data);
}