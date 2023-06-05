/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:08:28 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 16:17:35 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_listchr(char **string, char find)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (string[i])
	{
		if (ft_strchr(string[i], find))
			count++;
		i++;
	}
	return (count);
}

void	normalize_input(t_control *get)
{
	char	**split;
	int		i;
	int		j;

	split = shell_split(get->input, ' ');
	get->pieces = ft_calloc(sizeof(char **), is_listchr(split, '|') + 2);
	get->pieces[0] = split;
	j = 1;
	i = 0;
	while (split[i])
	{
		if (split[i][0] == '|')
			get->pieces[j++] = &split[i + 1];
		i++;
	}
}

// int	main(int c, char **v)
// {
// 	static t_control	get;

// 	(void)c;
// 	get.input = v[1];
// 	normalize_input(&get);
// 	for (int i = 0; get.pieces[i]; i++)
// 	{
// 		for (int j = 0; get.pieces[i][j]; j++)
// 			printf("%s\n", get.pieces[i][j]);
// 	}
// 	free_shellsplit(get.pieces);
// }
