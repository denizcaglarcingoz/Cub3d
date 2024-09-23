/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:48:29 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:30:15 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c > 64 && c < 91)
	{
		return (1);
	}
	else if (c > 96 && c < 123)
	{
		return (2);
	}
	else if (c >= '0' && c <= '9')
	{
		return (3);
	}
	else
	{
		return (0);
	}
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int a = ft_isalnum('9');
	printf("%d", a);

}
*/
