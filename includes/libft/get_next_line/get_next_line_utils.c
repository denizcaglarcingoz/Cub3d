/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:58:52 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/20 16:05:05 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_copystr(char *src, int memlen, char *buffer, int i)
{
	char	*str;
	int		k;

	str = (char *)malloc(memlen + 1);
	if (str == 0)
		return (error_free_detail(src, buffer, -1));
	k = 0;
	while (k < i)
	{
		str[k] = src[k];
		k++;
	}
	str[k] = '\0';
	return (str);
}

char	*error_free_detail(char *l, char *buffer, int bytes_read)
{
	int	i;

	if ((l != NULL && ft_strlen(l) < 1) || bytes_read == -1)
	{
		if (buffer != 0)
		{
			i = 0;
			while (i < BUFFER_SIZE)
			{
				buffer[i] = 0;
				i++;
			}
		}
		free(l);
		return (NULL);
	}
	else
		return (l);
}

char	*linecat(char *l, char *buffer, int pos, int llen)
{
	int		k;
	int		j;
	char	*temp;

	temp = gnl_copystr(l, llen, buffer, llen);
	free(l);
	l = (char *)malloc(ft_strlen(temp) + pos + 1);
	if (l == 0)
		return (error_free_detail(temp, buffer, -1));
	k = 0;
	while (temp[k] != '\0')
	{
		l[k] = temp[k];
		k++;
	}
	j = 0;
	while (j < pos)
	{
		l[k + j] = buffer[j];
		j++;
	}
	l[ft_strlen(temp) + pos] = '\0';
	free(temp);
	return (l);
}
