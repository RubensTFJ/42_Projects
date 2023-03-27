/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:23 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/24 14:52:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	getwords(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	fill_list(char const *s, char **list, char c)
{
	int		i;
	int		j;
	int		k;
	int		word;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		word = 0;
		while (s[i + word] && s[i + word] != c)
			word++;
		if (word)
		{
			list[j] = ft_calloc(sizeof(char), (word + 1));
			k = 0;
			while (k < word)
				list[j][k++] = s[i++];
			j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		foundwords;
	char	**list;

	if (!s)
		return (NULL);
	foundwords = getwords(s, c);
	list = ft_calloc(sizeof(char *), (foundwords + 1));
	if (!list)
		return (NULL);
	fill_list(s, list, c);
	return (list);
}
