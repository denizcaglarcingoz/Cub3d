/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:40:03 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:56:24 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < size)
		i++;
	a = i;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (a + j);
}
/*
int main()
{
	char dest[10] = "This is ";
	char *src = "a potentially long string";
	int size = 10;
	int strlcat = ft_strlcat(dest, src, size);
	printf("Cat = %s\n", dest);
	printf("Catted size = %d", strlcat);
	return (0);
}*/
