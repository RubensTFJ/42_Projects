/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:17:38 by rteles-f          #+#    #+#             */
/*   Updated: 2023/03/24 18:45:06 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

typedef struct s_vars {
	int		id[2];
	int		fd[2];
	char	**commands[2];
	int		pipe[2];
	char	**paths;
} t_vars;

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
} t_pipex;

int	end_pipex(t_vars *get)
{
	int	i;
	
	if (get->paths)
	{
		i = 0;
		while (get->paths[i])
			free(get->paths[i++]);
		free(get->paths);
	}
	if (*get->commands)
	{
		i = 0;
		while (i < 2)
		{
			free(get->commands[i][0]);
			if (get->commands[i][1])
				free(get->commands[i][1]);
			free(get->commands[i++]);
		}
	}
	exit(0);
	return (0);
}

int	check_start(int argc, char **argv, t_vars *get)
{
	if (argc != 5)
	{
		ft_printf("Wrong Usage.\n");
		return (end_pipex(get));
	}
	get->fd[0] = open(argv[1], O_RDONLY);
	if (get->fd[0] < 0)
	{
		ft_printf("Failed to Open Infile.\n");
		return (end_pipex(get));
	}
	get->fd[1] = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (get->fd[1] < 0)
	{
		ft_printf("Failed to Open Outfile.\n");
		return (end_pipex(get));
	}
	if (pipe(get->pipe) < 0)
		return (end_pipex(get));
	return (1);
}

int	get_paths(char **envp, char ***paths)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH", envp[i], 4))
		{
			*paths = ft_split(envp[i] + 5, ':');
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char *envp[])
{
	static t_vars	get;
	
	if (!check_start(argc, argv, &get))
		return (1);
	if (!get_paths(envp, &get.paths))
		return(2);
	get.commands[0] = ft_split(argv[2], ' ');
	get.commands[1] = ft_split(argv[3], ' ');
	// get.id[0] = fork();
	end_pipex(&get);
	return (0);
}


	// fd[1] = open(argv[3], O_CREAT | O_RDONLY | O_TRUNC, 420);
	// command = ft_strjoin(argv[1], argv[2]);
	// counter = write(fd[1], command, ft_strlen(command));
	// ft_printf("fd: %i, line: %s, write: %i\n", fd[1], command, counter);
	// free(command);
	// close(fd[1]);