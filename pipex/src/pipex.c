/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:27:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/30 02:50:40 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	executioner(t_vars *get, int *in_pipe, int *out_pipe, int index)
{
	dup2(in_pipe[0], STDIN_FILENO);
	dup2(out_pipe[1], STDOUT_FILENO);
	if (!get->full_command[index + 1])
		dup2(get->fd[1], STDOUT_FILENO);	
	execve(get->full_command[index], get->commands[index], get->envp);
}

void	pipex(t_vars *get)
{
	int	i;
	int	*temp;

	get->pipe1[0] = get->fd[0];
	i = 0;
	while (get->full_command[i])
	{
		pipe(get->pipe2);
		get->id = fork();
		if (!get->id)
			executioner(get, get->pipe1, get->pipe2, i);
		else
		{
			wait(0);
			close(get->pipe2[1]);
			temp = get->pipe1;
			get->pipe1 = get->pipe2;
			get->pipe2 = temp;
		}
		i++;
	}
}
/*
	get->pipe_a[0] = get->fd[0];
	dup2(get->pipe_a[0], STDIN_FILENO);
	// close(get->pipe_a[0]);
	dup2(get->pipe_a[1], STDOUT_FILENO);
	close(get->pipe_a[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[0], get->commands[0], envp);
	else
		wait(0);
	pipe(get->pipe_b);
	dup2(get->pipe_a[0], STDIN_FILENO);
	dup2(get->pipe_b[1], STDOUT_FILENO);
	close(get->pipe_a[0]);
	close(get->pipe_b[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[1], get->commands[1], envp);
	else
		wait(0);
	dup2(get->pipe_b[0], STDIN_FILENO);
	dup2(get->fd[1], STDOUT_FILENO);
	close(get->pipe_b[0]);
	close(get->fd[1]);
	get->id[0] = fork();
	if (!get->id[0])
		execve(get->full_command[2], get->commands[2], envp);
	
	// get->pipe_a[0] = get->fd[0];
	// i = 0;
	// while (get->full_command[i])
	// {
	// 	dup2(get->pipe_a[0], STDIN_FILENO);
	// 	dup2(get->pipe_a[1], STDOUT_FILENO);
	// 	close(get->fd[0]);
	// 	close(get->pipe_a[1]);
	// 	get->id[0] = fork();
	// 	if (!get->id[0])
	// 		execve(get->full_command[i], get->commands[i], envp);
	// 	else
	// 		wait(NULL);
	// 	i++;
	// }
	// get->pipe_a[1] = get->fd[1];

*/