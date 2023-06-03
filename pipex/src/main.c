/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/31 17:33:40 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_start(int *argc, char ***argv, char **envp, t_vars *get)
{
	if ((*argc) < 5)
		end_pipex(get, 1, "Wrong Usage.");
	if (!ft_strncmp((*argv)[1], "here_doc", 8))
	{
		ft_init_here_doc((*argv)[2], get, (*argv)[(*argc) - 1]);
		(*argv)++;
		(*argc)--;
	}
	else
	{
		get->fd[0] = open((*argv)[1], O_RDONLY);
		if (get->fd[0] < 0)
			ft_printf("%s: No such file or directory", (*argv)[1]);
		get->fd[1] = open((*argv)[(*argc) - 1], O_TRUNC | O_CREAT | O_RDWR,
				0000644);
		if (get->fd[1] < 0)
			end_pipex(get, 3, "Failed to Open Outfile.");
	}
	get->envp = envp;
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
	write (2, "command not found: ", 19);
	i = 0;
	while (command[i])
		write (2, &command[i++], 1);
	write (2, "\n", 1);
	return (ft_strjoin(get->paths[0], command));
}

/*
(size - 3 + 1):
'size' is the number of arguments when calling pipex.
'- 3' is the number of arguments that are not commands to 
be executed: "./pipex", "infile" and "outfile".
'+ 1' is the null ending. 
*/
void	get_commands(int size, t_vars *get, char **input)
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
			end_pipex(get, 6, "Fail to Allocate Memory");
		get->full_command[i] = build_command(get, get->commands[i][0]);
		i++;
	}
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

	check_start(&counter, &input, envp, &get);
	if (!get_paths(envp, &get))
		end_pipex(&get, 5, "Failed to find Path");
	get_commands(counter, &get, input);
	pipex(&get);
	end_pipex(&get, 0, "");
	return (0);
}
