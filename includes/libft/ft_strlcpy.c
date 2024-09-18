/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:23:37 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:22:51 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;
	size_t	src_length;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	if (size == 0)
		return (src_length);
	a = 0;
	while (src[a] != '\0' && a < size - 1)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = '\0';
	return (src_length);
}
/*
#include <stdio.h>
int main ()
{	
	char dest[10] = "This is ";
	char *src = "a potentially long string";
	int size = 10;
	int a = ft_strlcpy(dest,src, size);
	printf("%d\n", a);
	printf("%s",dest);
	return (0);

}*/
