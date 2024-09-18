/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:19:00 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:44:32 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*str_dup;
	size_t		j;

	i = 0;
	while (s[i] != '\0')
		i++;
	str_dup = (char *)malloc(i + 1);
	if (str_dup == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str_dup[j] = s[j];
		j++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

/*
#include <stdio.h>
int main()
{
 
}*/
