/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:25:07 by jhotchki          #+#    #+#             */
/*   Updated: 2024/08/15 19:45:06 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
int main(void)
{
	char *str = "get money";
	char *str1 = ", get paid";
	char *res;
	res = ft_strjoin(str, str1);
	printf("%s\n", res);
	free(res);
	return 0;
}*/
