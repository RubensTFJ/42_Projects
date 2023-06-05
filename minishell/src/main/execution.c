/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:33:09 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 19:13:51 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	run_input(t_list *node)
{
	t_command	*command;

	while (node)
	{
		command = (t_command *)node->content;
		command->execute(command);
		node = node->next;
	}
}

void	execve_aux(t_command *get)
{
	dup2(get->instream, STDIN_FILENO);
	dup2(get->pipe[1], STDIN_FILENO);
	get->id = fork();
	if (!get->id)
	{
		close(get->pipe[0]);
		execve(get->exec_path, get->flags, get->main->envp);
	}
	else
	{
		close(get->pipe[1]);
	}
}
