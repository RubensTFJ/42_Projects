/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:27:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/30 18:34:55 by rteles-f         ###   ########.fr       */
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

/*
pipex
	Opens a pipe and forks the process in loop for each command stored in
the full_commands variable.
	Using 2 diferent Pipes, the pipes take turns in being read and writen
using temp variable to make the switch.
	The program needs only one pipe open at a time. The Pipe to be 
written (pipe2), has to be open, the pipe to be read has not.

executioner
	Is the only action of the child process. It sets input and output
for the execve function, which it proceeds to call.
*/
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
		if (get->id < 0 || get->pipe2[0] < 0)
			end_pipex(get, "Failed to Pipe/Fork", 7);
		if (!get->id)
			executioner(get, get->pipe1, get->pipe2, i);
		else
		{
			close(get->pipe2[1]);
			wait(0);
			temp = get->pipe1;
			get->pipe1 = get->pipe2;
			get->pipe2 = temp;
		}
		i++;
	}
}
