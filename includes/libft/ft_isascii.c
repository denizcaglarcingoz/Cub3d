/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:22:47 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 19:26:05 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c < 128 && c >= 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/* #include <stdio.h>
int	main()
{
	
	int c = ft_isascii(-1); 
	printf("%d",c);
	return (0);
}
 */