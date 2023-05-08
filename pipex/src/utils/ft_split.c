/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:50:23 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/02 19:36:34 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	finish_list_with(char **list, char *put)
{
	char	*temp;

	while (*list)
	{
		temp = ft_strjoin(*list, put);
		free(*list);
		*list = temp;
		list++;
	}
}

static void	fill_list(char const *s, char **list, char c)
{
	int		i;
	int		k;
	int		word;

	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		word = 0;
		while (s[i + word] && s[i + word] != c)
			word++;
		if (word)
		{
			(*list) = ft_calloc(sizeof(char), (word + 1));
			k = 0;
			while (k < word)
				(*list)[k++] = s[i++];
			list++;
		}
	}
}

static int	split_counter(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
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

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**list;

	list = NULL;
	words = split_counter(s, c);
	if (words)
		list = ft_calloc(sizeof(char *), (words + 1));
	if (!list)
		return (NULL);
	fill_list(s, list, c);
	return (list);
}
