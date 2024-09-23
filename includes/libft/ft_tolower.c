/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:27:34 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:23:39 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
	}
	return (c);
}
/*
#include <stdio.h>
int main()
{
    char lowercase = 'B';
    char uppercase = ft_tolower(lowercase);

    printf("Original character: %c\n", lowercase);
    printf("Lowercase character: %c\n", uppercase);

    return 0;
}*/
