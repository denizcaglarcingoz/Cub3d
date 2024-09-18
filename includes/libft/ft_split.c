/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcingoz <dcingoz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:58:45 by dcingoz           #+#    #+#             */
/*   Updated: 2023/09/10 18:43:25 by dcingoz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	ft_first_c_pass(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static char	**ft_free_substrings(char **splitted, int j)
{
	while (j >= 0)
	{
		free(splitted[j]);
		j--;
	}
	free(splitted);
	return (splitted);
}

static char	**ft_split_into(char **splitted, char const *s, char c)
{
	int	i;
	int	j;
	int	subs_len;

	i = ft_first_c_pass(s, c);
	j = 0;
	while (s[i] != '\0')
	{
		subs_len = i;
		while (s[subs_len] != c && s[subs_len])
			subs_len++;
		splitted[j] = ft_substr(s, i, subs_len - i);
		if (splitted[j] == 0)
		{
			splitted = ft_free_substrings(splitted, j);
			return (NULL);
		}
		j++;
		i = subs_len;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (splitted);
}

static int	ft_num_of_substrings(char const *s, char c)
{
	int	i;
	int	cut_count;

	if (ft_strlen(s) == 0)
		return (0);
	i = ft_first_c_pass(s, c);
	if (i == (int)ft_strlen(s))
		return (0);
	cut_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
		{
			cut_count++;
		}
		i++;
	}
	return (cut_count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	int		num_of_subs;

	num_of_subs = ft_num_of_substrings(s, c);
	splitted = (char **)malloc((num_of_subs + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	splitted = ft_split_into(splitted, s, c);
	if (splitted == NULL)
		return (NULL);
	splitted[num_of_subs] = NULL;
	return (splitted);
}
/* int main()
{
    // char *str = "";
    // char charset = ' ';
    char **result = ft_split("ggggggggggg", 'g');

	 if (result) {
        for (int i = 0; result[i]; i++) {
            printf("Substring %d: %s\n", i + 1, result[i]);
			 printf("Strcmp: %d\n", !strcmp(result[0], "tripouille"));
        }
    }
 	if(result[1] == NULL)
		printf("true");
	//	printf("Strcmp: %d\n", strcmp(result[0], "tripouille"));
	//printf("Substrin 0; %s", result[0]);
	int i = 0;
	while(result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return 0;
} */