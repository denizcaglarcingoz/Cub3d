/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:20:00 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/08 19:56:49 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (last == -1)
		return (NULL);
	return ((char *)(s + last));
}

/* int main ()
{
	const char *largestring = "Foo Baz";
	int c = 'r';int main ()
{
	const char *largestring = "Foo Baz";
	int c = 'r';
	char *ptr;

	ptr = ft_strrchr(largestring, c + 256);
	printf("Ptr is : %s", ptr);
}

}
 */