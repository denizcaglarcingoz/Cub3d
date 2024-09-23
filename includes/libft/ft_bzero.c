/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:58:25 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:20:21 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p_holder;

	p_holder = (char *)s;
	i = 0;
	while (i < n)
	{
		p_holder[i] = '\0';
		i++;
	}
}
/*
int main()
{
	char s[5] = "Deniz";
	size_t n = 10;
	ft_bzero(s, n);
	printf("%s",s);
}*/
