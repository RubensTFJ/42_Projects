/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:59:58 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/02 17:31:45 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	setup(t_control *get, char **envp)
{
	get->envp = envp;
	get->siginfo.sa_sigaction = (void *)setup;
	get->siginfo.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &get->siginfo, 0);
	sigaction(SIGUSR2, &get->siginfo, 0);
	// get_paths(envp, get);
}

void	free_list(char **list)
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

void	end_minishell(t_control *get)
{
	free_shellsplit(get->pieces);
	free(get->input);
	free_list(get->paths);
	exit(0);
}