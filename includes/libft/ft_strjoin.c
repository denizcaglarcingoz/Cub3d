/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:43:15 by dcingoz           #+#    #+#             */
/*   Updated: 2024/09/18 21:19:53 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
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
	return (result);
}

/*
int main ()
{
    char const *s1 = "Deniz ";
    char const *s2 = "is the king of bullshit";
    char *join = ft_strjoin(s1, s2);
    printf("%s", join);
}*/