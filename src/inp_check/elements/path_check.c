/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:03:01 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:03:02 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries.h"

char	*get_path(char *data, int *i, int *checks)
{
	int		j;
	char	*path;

	*checks += 1;
	*i += 2;
	while (data[*i] == ' ')
		(*i)++;
	j = *i;
	path = NULL;
	while (data[j] != '\n')
		j++;
	if (j == *i)
		return (NULL);
	path = ft_substr(data, *i, j - *i);
	if (path == NULL)
	{
		ft_putstr_fd("Malloc_Error", 2);
		return (NULL);
	}
	*i = j;
	return (path);
}

void	checks_init(int *checks)
{
	checks[0] = 0;
	checks[1] = 0;
	checks[2] = 0;
	checks[3] = 0;
}

void	path_check(char *data, int *i, t_inp_data *inp)
{
	int	checks[4];

	checks_init(checks);
	while (data[*i])
	{
		while (data[*i] == '\n' || data[*i] == ' ')
			(*i)++;
		if (data[*i] == 'N' && data[*i + 1] == 'O')
			inp->no_path = get_path(data, i, &(checks[0]));
		else if (data[*i] == 'S' && data[*i + 1] == 'O')
			inp->so_path = get_path(data, i, &(checks[1]));
		else if (data[*i] == 'W' && data[*i + 1] == 'E')
			inp->we_path = get_path(data, i, &(checks[2]));
		else if (data[*i] == 'E' && data[*i + 1] == 'A')
			inp->ea_path = get_path(data, i, &(checks[3]));
		else
			break ;
	}
	if (checks[0] != 1 || checks[1] != 1 || checks[2] != 1 || checks[3] != 1)
		element_check_err(data, inp, "path error");
}
