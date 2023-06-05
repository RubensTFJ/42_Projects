/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:14:57 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 16:04:58 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
