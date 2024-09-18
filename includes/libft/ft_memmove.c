/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:55:30 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 19:38:14 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_dest;
	const char	*p_src;

	p_dest = (char *)dest;
	p_src = (const char *)src;
	if (p_dest < p_src)
	{
		i = 0;
		while (i < n)
		{
			p_dest[i] = p_src[i];
			i++;
		}
	}
	if (p_dest > p_src)
	{
		i = n;
		while (i > 0)
		{
			p_dest[i -1] = p_src[i -1];
			i--;
		}
	}
	return (dest);
}
/*
int main()
{
	char dest[15];
	const char src[15] = "123456789011";
	size_t n = 5;
	ft_memmove(dest, src, n);
	printf("%s",dest);
}*/
