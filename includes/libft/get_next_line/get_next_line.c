/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:52:06 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/27 04:04:48 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	pos_count(int rp1, int rp0, char *buffer)
{
	while (rp1 < rp0 && buffer[rp1] != '\n')
		rp1++;
	if (rp1 < rp0 && buffer[rp1] == '\n')
		rp1++;
	return (rp1);
}

static char	*l_assign(char *l, char *buffer, int rp1)
{
	if (l == 0)
		l = gnl_copystr(buffer, rp1, buffer, rp1);
	else
		l = linecat(l, buffer, rp1, ft_strlen(l));
	return (l);
}

static int	cpystr_pos(char *buffer, char *l, int rp1, int rp0)
{
	int		j;
	int		k;

	k = pos_count(rp1, rp0, buffer);
	l[k - rp1] = '\0';
	j = 0;
	while (rp1 < k)
	{
		l[j] = buffer[rp1];
		rp1++;
		j++;
	}
	return (rp1);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*l;
	static int	r_p[2] = {0, 0};

	l = 0;
	if (buffer[0] != 0 && r_p[1] < BUFFER_SIZE)
	{
		l = (char *)malloc(pos_count(r_p[1], r_p[0], buffer) - r_p[1] + 1);
		if (l == 0)
			return (error_free_detail(0, buffer, r_p[0]));
		r_p[1] = cpystr_pos(buffer, l, r_p[1], r_p[0]);
		if (ft_strlen(l) > 0 && l[ft_strlen(l) - 1] == '\n' )
			return (error_free_detail(l, buffer, r_p[0]));
	}
	while (1)
	{
		r_p[0] = read(fd, buffer, BUFFER_SIZE);
		if (r_p[0] < 1)
			return (error_free_detail(l, buffer, r_p[0]));
		r_p[1] = pos_count(0, r_p[0], buffer);
		l = l_assign(l, buffer, r_p[1]);
		if (r_p[0] < BUFFER_SIZE || buffer[r_p[1] - 1] == '\n')
			break ;
	}
	return (l);
}

/* l is line to return
	r_p[0] is read byte
	r_p[1] is count position of last read byte
 */