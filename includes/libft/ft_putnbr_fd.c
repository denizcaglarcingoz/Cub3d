/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:14:33 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 18:22:11 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_special(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;

	if (n == 0 || n == -2147483648)
	{
		ft_putnbr_special(n, fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
	}
	i = 0;
	while (n > 0)
	{
		s[i] = (n % 10) + 48;
		n = n / 10;
		i++;
	}
	while (i - 1 >= 0)
	{
		write(fd, &s[i - 1], 1);
		i--;
	}
}
/*
int main()
{
    ft_putnbr_fd(-102300, 1);
}*/