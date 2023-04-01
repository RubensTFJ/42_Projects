/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/31 22:51:40 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_start(int argc, char **argv, char **envp, t_vars *get)
{
	get->envp = envp;
	if (argc < 5)
		end_pipex(get, 1, "Wrong Usage.");
	get->fd[0] = open(argv[1], O_RDONLY);
	if (get->fd[0] < 0)
		end_pipex(get, 2, "Failed to Open Infile.");
	get->fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (get->fd[1] < 0)
		end_pipex(get, 3, "Failed to Open Outfile.");
	get->pipe1 = ft_calloc(sizeof(int), 2);
	get->pipe2 = ft_calloc(sizeof(int), 2);
	if (!get->pipe1 || !get->pipe2)
		end_pipex(get, 4, "Fail to Allocate Memory");
}

int	get_paths(char **envp, t_vars *get)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			get->paths = ft_split(envp[i] + 5, ':');
			finish_list_with(get->paths, "/");
			return (1);
		}
		i++;
	}
	return (0);
}

char	*build_command(t_vars *get, char *command)
{
	int		i;
	char	*full_path;

	i = 0;
	if (!access(command, F_OK))
		return (ft_strdup(command));
	i = 0;
	while (get->paths[i])
	{
		full_path = ft_strjoin(get->paths[i++], command);
		if (!access(full_path, F_OK))
			return (full_path);
		free(full_path);
	}
	return (ft_strjoin(get->paths[--i], command));
}

int	get_commands(int size, t_vars *get, char **input)
{
	int	i;

	get->commands = ft_calloc(sizeof(char *), (size - 3 + 1));
	get->full_command = ft_calloc(sizeof(char *), (size - 3 + 1));
	size--;
	i = 0;
	while ((i + 2) < size)
	{
		get->commands[i] = ft_split(input[i + 2], ' ');
		if (!get->commands[i])
			return (0);
		get->full_command[i] = build_command(get, get->commands[i][0]);
		i++;
	}
	return (1);
}

/*
check_start
Check for Initial Conditions such as number of arguments,
succes in opening in and out files, and malloc for the main struct.

get_path
Guaratees path exists and saves them.

get_commands
Guarantee commands exist inside the paths and saves them.

pipex
executes the commands.

end_pipex
End all Open files and Malloc'ed memorys.
*/
int	main(int counter, char **input, char *envp[])
{
	static t_vars	get;

	check_start(counter, input, envp, &get);
	if (!get_paths(envp, &get))
		end_pipex(&get, 5, "Failed to find Path");
	if (!get_commands(counter, &get, input))
		end_pipex(&get, 6, "Invalid Command");
	pipex(&get);
	end_pipex(&get, 0, "");
	return (0);
}
