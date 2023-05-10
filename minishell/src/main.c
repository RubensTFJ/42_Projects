/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:43:59 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/09 14:21:58 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_unsplit(char **split, int posize)
{
	char	*line;
	int		i;

	if (*split)
		line = ft_unsplit((split + 1), posize + ft_strlen(*split) + 1);
	else
		return (ft_calloc(sizeof(char), posize + 1));
	i = 0;
	while ((*split)[i])
		line[posize++] = (*split)[i++];
	line[posize] = ' ';
	return (line);
}

int	prepare_input(t_control *get)
{
	get->line = ft_unsplit(get->argv, 0);
	ft_printf("%s\n", get->line);
	free(get->line);
	return (1);
}

int	check_input(t_control *get, int argc, char **argv, char **envp)
{
	get->argc = argc;
	get->argv = argv;
	get->envp = envp;
	prepare_input(get);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	static t_control	get;

	check_input(&get, argc, argv, envp);
	return (1);
}