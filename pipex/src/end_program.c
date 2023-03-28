/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:10:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/28 23:30:43 by rteles-f         ###   ########.fr       */
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

static void	free_list(char **list)
{
	int	i;

	if (list)
	{
		i = 0;
		while (list[i])
			free(list[i++]);
		free(list);
	}
}

static void	free_commands(char ***commands)
{
	int	i;
	int	j;

	if (commands)
	{
		i = 0;
		while (commands[i])
		{
			j = 0;
			while (commands[i][j])
				free(commands[i][j++]);
			free(commands[i++]);
		}
		free(commands);
	}
}

void	end_pipex(t_vars *get, int exit_type, char *string)
{
	if (*string)
		ft_printf("%s\n", string);
	free_list(get->paths);
	free_list(get->full_command);
	free_commands(get->commands);
	exit(exit_type);
}
