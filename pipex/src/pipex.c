/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:27:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/29 00:35:36 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	child_process(t_vars *get, int index, char *envp[])
{
	execve(get->full_command[index], get->commands[index], envp);
}

void	pipex(t_vars *get, char *envp[])
{
	int	i;

	i = 0;
	dup2(get->fd[0], STDIN_FILENO);		// HACKEADO	!!!
	dup2(get->pipe[1], STDOUT_FILENO);
	close(get->fd[0]);
	close(get->pipe[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[i], get->commands[i], envp);
	else
		wait(NULL);
	pipe(get->inter_pipe);
	dup2(get->pipe[0], STDIN_FILENO);
	dup2(get->inter_pipe[1], STDOUT_FILENO);
	close(get->pipe[0]);
	close(get->inter_pipe[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[1], get->commands[1], envp);
	else
		wait(0);
	dup2(get->inter_pipe[0], STDIN_FILENO);
	dup2(get->fd[1], STDOUT_FILENO);
	close(get->inter_pipe[0]);
	close(get->fd[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[2], get->commands[2], envp);
	
	// while (get->full_command[i])
	// {
	// 	get->id[0] = fork();
	// 	if (!get->id[0])
	// 	{
	// 		execve(get->full_command[i], get->commands[i], envp);
	// 	}
	// 	else
	// 	{
	// 		// dup2(get->pipe[1], STDIN_FILENO);
	// 		close(get->pipe[1]);
	// 	}
	// 	i++;
	// }
}
