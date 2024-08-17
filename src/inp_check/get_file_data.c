#include "libraries.h"

char	*get_file_data(char *file_name)
{
	int		fd;
	char	*content;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		fd_error();
	content = ft_strdup("");
	if (!content)
		malloc_error();
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		content = ft_strjoin(content, line);
		if (!content)
			(free(line), malloc_error());
		free(line);
	}
	close(fd);
	return (content);
}
