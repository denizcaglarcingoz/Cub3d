/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:11:16 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:48:13 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i[2];

	i[0] = ft_strlen(s);
	if (start > i[0])
	{
		substr = malloc((1) * sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > i[0] - start)
		len = i[0] - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	i[1] = 0;
	while (start + i[1] < start + (unsigned int)len && s[start + i[1]])
	{
		substr[i[1]] = s[start + i[1]];
		i[1]++;
	}
	substr[len] = '\0';
	return (substr);
}
/* #include <stdio.h>
int main()
{
     char const s[17] = "Deniz is the king";
    unsigned int start = 17;
    size_t len = 5;
    char *substr = ft_substr("BONi[1]OUR LES HARICOTS !", 8, 14);
    printf("Substring is : /%s/", substr);
} */