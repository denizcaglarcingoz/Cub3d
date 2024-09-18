/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:17:12 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:44:16 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	t_size;
	void	*p_calloc;

	t_size = nmemb * size;
	if ((nmemb && size) && t_size / nmemb != size)
		return (NULL);
	p_calloc = malloc(t_size);
	if (p_calloc == NULL)
		return (NULL);
	if (p_calloc)
		ft_bzero(p_calloc, t_size);
	return (p_calloc);
}
/*
int main()
{
}*/
