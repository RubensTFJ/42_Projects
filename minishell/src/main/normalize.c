/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:08:28 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/01 22:47:08 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// void	force_space(char *line)
// {
// 	int		i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == "\"" || line[i] == "\'" && ++i)
// 		{
// 			while (line[i] && (line[i] != "\"" || line[i] != "\'"))
// 				i++;
// 		}
// 		if (line[i] == ' ')
// 			line[i] = -1;
// 		i++;
// 	}
// }

// int	split_size(char **split)
// {
// 	int	size;

// 	size = 0;
// 	while (*split++)
// 		size++;
// 	return (size);
// }

// // int	split_needed(char *line)
// // {
// // 	int		i;
// // 	int		counter;
// // 	char	stop;

// // 	counter = 0;
// // 	i = 0;
// // 	while (line[i])
// // 	{
// // 		if (line[i] == '<' && line[i + 1] == '<' && ++i)
// // 			counter++;
// // 		else if (line[i] == '<' || line[i] == '>')
// // 			counter++;
// // 		else if (line[i] == '>' && line[i + 1] == '>' && ++i)
// // 			counter++;
// // 		else if (line[i] == "\"" || line[i] == "\'")
// // 		{
// // 			stop = line[i];
// // 			counter++;
// // 			while (line[i] != stop)
// // 				i++;
// // 		}
// // 		i++;
// // 	}
// // 	return (counter);
// // }

// //  <>\"\'

// static int	split_needed(char const *s, char *find)
// {
// 	int		i;
// 	int		count;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && ft_strchr(find, s[i]))
// 			i++;
// 		while (s[i] && !ft_strchr(find, s[i]))
// 			count++;
// 		while (s[i] && !ft_strchr(find, s[i]))
// 			i++;
// 	}
// 	return (count);
// }


// void	grow_split(char *line, int pos, char ***split)
// {
// 	int		i;
// 	char	**newsplit;

// 	newsplit = ft_calloc(sizeof(char *), split_size(*split) + 2);
// 	i = 0;
// 	while (*split[i])
// 		newsplit[i] = split[i];
// 	while (line[i])
// 	{
		
// 	}
// 	free(*split);
// 	*split = newsplit;
// }

// char	*negate_space(char *line)
// {
// 	int		i;
// 	char	stop;
	
// 	if (!line)
// 		return ;
// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == "\'" || line[i] == "\"")
// 		{
// 			stop = line[i++];
// 			while (line[i] != stop)
// 				i++;
// 		}
// 		if (line[i] == ' ')
// 			line[i] = -1;
// 		i++;
// 	}
// 	return (line);
// }

// char	**shell_split(char *line, char **separate)
// {
// 	int		i;
// 	int		counter;
// 	char	**split;
// 	char	**temp;

// 	split = ft_split(line, " ");
// 	i = 0;
// 	while (separate[i])
// 	{
// 		if (ft_strnstr(line, separate[i]))
// 			temp = ft_split()
// 	}
// 	split = ft_split(negate_space(line), -1);
// 	split[0] = line;
// 	counter = 0;
// 	i = 0;
// 	while (line[i])
// 	{
// 		// split = force_space(line);
// 		if (line[i])
// 			grow_split(line, i, &split[counter++]);
// 		i++;
// 	}
// 	return (split);
// }

// void	normalize_input(t_control *get)
// {
// 	char	**split;
// 	int		i;

// 	split = ft_split(get->input, "|");
// 	get->pieces = ft_calloc(sizeof(char **), split_size(split) + 1);
// 	i = 0;
// 	while (split[i])
// 	{
// 		get->pieces[i] = shell_split(split[i], get->separators);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }