/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhotchki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:55:36 by jhotchki          #+#    #+#             */
/*   Updated: 2024/05/01 17:55:40 by jhotchki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *s)
{
	int		sign;
	long	int_piece;
	double	float_piece;

	sign = 1;
	int_piece = 0;
	float_piece = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == 45 || *s == 43)
		if (*s++ == '-')
			sign *= -1;
	while ((*s >= '0' && *s <= '9') && *s && *s != '.')
		int_piece = int_piece * 10 + *s++ - '0';
	if (*s == '.')
		s++;
	while (*s && (*s >= '0' && *s <= '9'))
		float_piece += (*s++ - '0') / 10;
	return (sign * (int_piece + float_piece));
}
