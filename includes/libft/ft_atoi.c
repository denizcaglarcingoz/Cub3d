/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:54:54 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 20:14:42 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_conv_int(const char *nptr, int i)
{
	long	conv_int;

	conv_int = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		conv_int = conv_int * 10 + (nptr[i] - 48);
		i++;
	}
	return (conv_int);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	long	conv_int;
	int		neg;

	i = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	j = i;
	while (nptr[j] == '-' || nptr[j] == '+')
		j++;
	if (j - i > 1)
		return (0);
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	if (nptr[i] == '+')
		i++;
	conv_int = ft_conv_int(nptr, i);
	return (conv_int * neg);
}

/* int main ()
{
	const char *ptr = "-+42";
	int a = ft_atoi(ptr);
	printf("%d", a);
}
 */