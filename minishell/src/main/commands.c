/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:24:58 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 19:26:56 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	output_direct(){}
void	input_direct(){}
void	pipe_output(){}
void	here_doc(){}
void	echo_builtin(){}
void	cd_builtin(){}
void	pwd_builtin(){}
void	export_builtin(){}
void	unset_builtin(){}
void	env_builtin(){}
void	exit_builtin(){}

t_command	*new_command(t_control *get)
{
	t_command	*new;

	new = ft_calloc(sizeof(t_command), 1);
	new->main = get;
	new->valid = 1;
	return (new);
}

char	*build_executable_path(t_control *get, char *command)
{
	int		i;
	char	*exec_path;

	if (!access(command, F_OK))
		return (ft_strdup(command));
	i = 0;
	while (get->paths[i])
	{
		exec_path = ft_strjoin(get->paths[i++], command);
		if (!access(exec_path, F_OK))
			return (exec_path);
		free(exec_path);
	}
	// invalid_input(command);
	return (NULL);
}

void	try_command(t_command *get, int index)
{
	get->exec_path = build_executable_path(get->main, get->terminal[index]);
	if (!get->exec_path)
	{
		get->valid = 0;
		return ;
	}
	get->execute = execve_aux;
	if (get->terminal[index + 1] && get->terminal[index + 1][0] == '-')
	{
		get->flags = ft_split(get->terminal[index + 1], ' ');
		get->terminal[index + 1][0] = 0;
	}
	else
		get->flags = ft_split(get->terminal[index], ' ');
}

void	do_nothing(void)
{
	return ;
}

t_exe	solve(char *find)
{
	int				index;
	int				length;
	static char		*cases[14] = {
		"", ">>", "<<", ">",
		"<", "|", "echo", "cd",
		"pwd", "export", "unset", "env",
		"exit", NULL
	};
	static t_exe	functions[14] = {
		do_nothing, output_direct, input_direct, output_direct,
		here_doc, pipe_output, echo_builtin, cd_builtin,
		pwd_builtin, export_builtin, unset_builtin, env_builtin,
		exit_builtin, try_command
	};

	length = ft_strlen(find);
	index = 0;
	while (cases[index] && ft_strncmp(find, cases[index], length))
		index++;
	return (functions[index]);
}

void	structure_commands(t_control *get)
{
	t_command	*command;
	char		**input;
	int			i;
	int			j;

	i = 0;
	while (get->pieces[i])
	{
		input = get->pieces[i];
		command = new_command(get);
		j = 0;
		while (input[j] && (input[j - 1] && input[j - 1][0] != '|') && command->valid)
		{
			(solve(input[j]))(command, i);
			j++;
		}
		if (command->valid)
			ft_lstadd_back(&get->commands, ft_lstnew((void *)command));
		// else
		// 	delete_command(command);
		i++;
	}
}