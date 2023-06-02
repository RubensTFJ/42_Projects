/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:08:28 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/02 13:18:46 by rteles-f         ###   ########.fr       */
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
	int		i;
	int		j;

	get->split = shell_split(get->input, ' ');
	get->pieces = ft_calloc(sizeof(char **), is_listchr(get->split, '|') + 2);
	get->pieces[0] = get->split;
	j = 1;
	i = 0;
	while (get->split[i])
	{
		if (ft_strchr(get->split[i], '|'))
		{
			get->pieces[j++] = &get->split[i + 1];
			free(get->split[i]);
			get->split[i] = 0;
		}
		i++;
	}
}

void	free_shellsplit(char ***arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
			free(arg[i][j++]);
		i++;
	}
	free(arg[0]);
	free(arg);
}

int main(int c, char **v)
{
	static t_control get;

	(void)c;
	get.input = v[1];
	normalize_input(&get);
	for(int i = 0; get.pieces[i]; i++)
	{
		for (int j = 0; get.pieces[i][j]; j++)
			printf("%s\n", get.pieces[i][j]);
	}
	free_shellsplit(get.pieces);
}