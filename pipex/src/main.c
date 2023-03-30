/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/30 02:19:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_start(int argc, char **argv, t_vars *get)
{
	// if (argc != 5)
	// 	end_pipex(get, 1, "Wrong Usage.");
	get->fd[0] = open(argv[1], O_RDONLY);
	if (get->fd[0] < 0)
		end_pipex(get, 2, "Failed to Open Infile.");
	get->fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (get->fd[1] < 0)
		end_pipex(get, 3, "Failed to Open Outfile.");
	get->pipe1 = ft_calloc(sizeof(int), 2);
	get->pipe2 = ft_calloc(sizeof(int), 2);
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
	get->envp = envp;
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
	return (NULL);
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
		if (!get->full_command[i++])
			return (0);
	}
	return (1);
}

int	main(int counter, char **input, char *envp[])
{
	static t_vars	get;

	check_start(counter, input, &get);
	if (!get_paths(envp, &get))
		end_pipex(&get, 5, "Failed to find Path");
	if (!get_commands(counter, &get, input))
		end_pipex(&get, 6, "Invalid Command");
	pipex(&get);
	end_pipex(&get, 0, "");
	return (0);
}
	// fd[1] = open(argv[3], O_CREAT | O_RDONLY | O_TRUNC, 420);
	// command = ft_strjoin(argv[1], argv[2]);
	// counter = write(fd[1], command, ft_strlen(command));
	// ft_printf("fd: %i, line: %s, write: %i\n", fd[1], command, counter);
	// free(command);
	// close(fd[1]);