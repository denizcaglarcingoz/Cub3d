/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:53 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 21:14:28 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;
	size_t	j;
	size_t	a;

	lil_len = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	j = 0;
	while (big[j] != '\0' && j < len)
	{
		if (big[j] == little[0])
		{
			a = 0;
			while (big[j + a] == little[a] && little[a]
				&& j + a < len)
				a++;
			if (a == lil_len)
				return ((char *)(big + j));
		}
		j++;
	}
	return (NULL);
}

/* int main ()
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	char *ptr;
	char *str;

	str = strnstr(largestring, smallstring, -1);
	printf("Str is : %s\n", str);
	ptr = ft_strnstr(largestring, smallstring, -1);
	printf("ft_Str is : %s\n", ptr);

}
 */