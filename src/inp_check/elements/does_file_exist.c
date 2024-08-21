#include "libraries.h"

void	open_minus(char *data, t_inp_data *inp)
{
	if (errno == ENOENT)
		element_check_err(data, inp, "file does not exist");
	else
		element_check_err(data, inp, "open error");
}

void	does_file_exist(char *data, t_inp_data *inp)
{
	int fd;

	fd = open(inp->no_path, O_RDONLY);
	if (fd == -1)
		open_minus(data, inp);
	close(fd);
	fd = open(inp->so_path, O_RDONLY);
	if (fd == -1)
		open_minus(data, inp);
	close(fd);
	fd = open(inp->we_path, O_RDONLY);
	if (fd == -1)
		open_minus(data, inp);
	close(fd);
	fd = open(inp->ea_path, O_RDONLY);
	if (fd == -1)
		open_minus(data, inp);
	close(fd);
}
