/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:33:25 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/25 17:14:26 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pushswap.h>

static int	getwords(char const *s, char c);
static int	fill_list(char const *s, char **list, char c);
static char	*checkmalloc(int size, int members, char **list);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		foundwords;
	int		check;
	char	**list;

	if (!s)
		return (NULL);
	foundwords = getwords(s, c);
	list = ft_calloc(sizeof(char *), (foundwords + 1));
	if (!list)
		return (NULL);
	check = fill_list(s, list, c);
	if (!check)
		return (NULL);
	return (list);
}

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
	int		word;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		word = 0;
		while (s[i + word] && s[i + word] != c)
			word++;
		if (word > 0)
		{
			list[j] = checkmalloc((word + 1), j, list);
			if (!list[j])
				return (0);
			ft_memcpy(list[j], &(s)[i], word);
			j++;
			i = i + word;
		}
	}
	return (1);
}

static char	*checkmalloc(int size, int members, char **list)
{
	int		i;
	char	*string;

	string = ft_calloc(sizeof(char), size);
	if (!string)
	{
		i = -1;
		while (i < members)
		{
			free(list[members - 1]);
			members--;
		}
		free(list);
		return (NULL);
	}
	return (string);
}
