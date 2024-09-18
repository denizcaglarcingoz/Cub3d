/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:57:54 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:43:47 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int		count;
	long	l_n;

	l_n = n;
	count = 0;
	if (l_n == 0)
		return (1);
	if (l_n < 0)
	{
		l_n = -l_n;
		count++;
	}
	while (l_n > 0)
	{
		l_n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		num_digits;
	long	l_n;
	char	*result;

	num_digits = count_digits(n);
	l_n = n;
	result = (char *)malloc((num_digits + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (l_n < 0)
	{
		result[0] = '-';
		l_n = -l_n;
	}
	result[num_digits] = '\0';
	while (num_digits - 1 >= 0)
	{
		result[num_digits - 1] = '0' + (l_n % 10);
		l_n /= 10;
		num_digits--;
		if (n < 0 && num_digits - 1 == 0)
			break ;
	}
	return (result);
}
/* #include <stdio.h>
int main()
{
    char *a = ft_itoa(-2147483648);
    printf("%s",a);
} */