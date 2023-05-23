/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:27:32 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/22 18:28:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	executioner(t_vars *get, int *out_pipe, int index)
{
	if (get->full_command[index + 1])
	{
		dup2(out_pipe[1], STDOUT_FILENO);
		close(out_pipe[0]);
	}
	else
		dup2(get->fd[1], STDOUT_FILENO);
	execve(get->full_command[index], get->commands[index], get->envp);
	end_pipex(get, 10, "");
}

/*
pipex
	Opens a pipe and forks the process in loop for each command stored in
the full_commands variable.
	Using 1 pipe variable and a temp variable to read and write. The function
pipe() creates a new pipe, this new pipe is used to be writen first and read
in the next loop. The execve in the first loop is going to read from the
infile, then the temp variable is going to save the door to the readable end
of that pipe, in the next loop a new pipe is created, the execve is going
to read from the old pipe, saved in temp, and write to the new pipe and so on.

executioner
	Is the only action of the child process. It sets the output
for the execve function, which it proceeds to call.
*/
void	pipex(t_vars *get)
{
	int	i;
	int	temp_in;

	temp_in = get->fd[0];
	i = 0;
	while (get->full_command[i])
	{
		dup2(temp_in, STDIN_FILENO);
		pipe(get->pipe);
		get->id = fork();
		if (get->id < 0 || get->pipe[0] < 0)
			end_pipex(get, 7, "Failed to Pipe/Fork");
		if (!get->id)
			executioner(get, get->pipe, i);
		else
		{
			close(temp_in);
			close(get->pipe[1]);
			temp_in = get->pipe[0];
			wait(0);
		}
		i++;
	}
	close(get->pipe[0]);
}
