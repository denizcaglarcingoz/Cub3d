/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:46:38 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:21:37 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	if (n == 0)
		return (0);
	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
    const char *s1;
    const char *s2;
    int a;

    s1 = "aaanaaaaaa";
    s2 = "aaanAa";
    printf("%d" , ft_memcmp(s1, s2, 5));
    write(1, &a, 4);
}*/
