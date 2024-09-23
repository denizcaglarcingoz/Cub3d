/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:02:13 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:02:14 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

char	*ft_strjoin_data(char *s1, char const *s2)
{
	char	*result;
	size_t	total_length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	total_length = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc((total_length + 1) * sizeof (char));
	if (result == NULL)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		result[i++] = s2[j++];
	}
	result[i] = '\0';
	free(s1);
	return (result);
}

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
		(close(fd), malloc_error());
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		content = ft_strjoin_data(content, line);
		if (!content)
			(close(fd), free(line), malloc_error());
		free(line);
	}
	close(fd);
	return (content);
}
