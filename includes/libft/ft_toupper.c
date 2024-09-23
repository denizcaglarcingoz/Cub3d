/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:21:40 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:23:51 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}
/*
#include <stdio.h>
int main()
{
    char lowercase = 'z';
    char uppercase = ft_toupper(lowercase);

    printf("Original character: %c\n", lowercase);
    printf("Uppercase character: %c\n", uppercase);

    return 0;
}*/
