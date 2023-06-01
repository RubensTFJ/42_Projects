/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:09:16 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/01 23:25:33 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	getwords(char *s, char c);
static int	fill_list(char *s, char **list, char c);
static char	*checkmalloc(int size, int members, char **list);

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

int	split_case(char *line)
{
	if (!*line)
		return (0);
	else if (*line == '<' && *(line + 1) && *(line + 1) == '<')
		return (2);
	else if (*line == '>' && *(line + 1) && *(line + 1) == '>')
		return (2);
	else if (*line == '>' || *line == '<')
		return (1);
	// else if (*line == "\"" || *line == "\'")
	// 	return (ignore_quotes(line));
	return (0);
}

int	ignore_quotes(char *string)
{
	int		i;
	char	stop;

	i = 0;
	if (string[i] == '\"' || string[i] == '\'')
	{
		stop = string[i++];
		while (string[i] && string[i] != stop)
			i++;
		if (string[i] != stop)
			return (0);
	}
	return (i);
}


void	save_quotes(char *line)
{
	int		i;
	char	stop;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			stop = line[i++];
			while (line[i] && line[i] != stop)
				i++;
		}
		if (line[i] == ' ')
			line[i] = -1;
		i++;
	}
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
			i += 1;
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

void	free_split(char **arg)
{
	int		i;

	i = 0;
	while (arg[i])
		free(arg[i++]);
	free(arg);
}

int main(int c, char **v)
{
	char	**split;

	(void)c;
	save_quotes(v[1]);
	split = shell_split(v[1], -1);
	for(int i = 0; split[i]; i++)
		printf("%s\n", split[i]);
	free_split(split);
}