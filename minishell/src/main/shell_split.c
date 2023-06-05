/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:09:16 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/02 15:20:30 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	getwords(char *s, char c);
static int	fill_list(char *s, char **list, char c);
static char	*checkmalloc(int size, int members, char **list);

static int	split_case(char *line)
{
	if (!*line)
		return (0);
	else if (*line == '<' && *(line + 1) && *(line + 1) == '<')
		return (2);
	else if (*line == '>' && *(line + 1) && *(line + 1) == '>')
		return (2);
	else if (*line == '>' || *line == '<')
		return (1);
	else if (*line == '|')
		return (1);
	return (0);
}

char	**shell_split(char *s, char c)
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

static int	getwords(char *s, char c)
{
	int		i;
	int		count;
	int		size;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		size = split_case(&s[i]);
		count += (s[i] && (s[i] != c));
		i += size + ignore_quotes(&s[i]);
		while (s[i] && s[i] != c && !split_case(&s[i]) && !size)
			i++;
	}
	return (count);
}

static int	fill_list(char *s, char **list, char c)
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
		word = split_case(&s[i]);
		while (s[i + word] && s[i + word] != c && !split_case(&s[i])
			&& !split_case(&s[i + word]))
			word += 1 + ignore_quotes(&s[i + word]);
		if (word > 0)
		{
			list[j] = checkmalloc((word + 1), j, list);
			if (!list[j])
				return (0);
			ft_memcpy(list[j++], &(s)[i], word);
			i += word;
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
