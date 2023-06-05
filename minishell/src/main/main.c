/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:43:59 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 16:08:27 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// char	*ft_unsplit(char **split, int posize)
// {
// 	char	*line;
// 	int		i;

// 	if (*split)
// 		line = ft_unsplit((split + 1), posize + ft_strlen(*split) + 1);
// 	else
// 		return (ft_calloc(sizeof(char), posize + 1));
// 	i = 0;
// 	while ((*split)[i])
// 		line[posize++] = (*split)[i++];
// 	line[posize] = ' ';
// 	return (line);
// }

// // int	prepare_input(t_control *get)
// // {
// // 	get->line = ft_unsplit(get->argv, 0);
// // 	ft_printf("%s\n", get->line);
// // 	free(get->line);
// // 	return (1);
// // }

t_list	**list_functions(void)
{
	static t_list	*f;

	return (&f);
}

t_exe	functions(char *find)
{
	t_list	*node;
	t_func	*function;

	node = *list_functions();
	while (node)
	{
		function = node->content;
		if (!ft_strncmp(function->type, find, ft_strlen(find)))
			return (function->pointer);
		node = node->next;
	}
	return (NULL);
}

// // void	set_functions(t_control *get)
// // {
// // 	functions("wc")(5 + 2);
// // 	get->functions[0] = space_case;
// // 	get->functions[1] = pipe_case;
// // 	get->functions[2] = amper_case;
// // 	get->functions[3] = semi_colon_case;
// // 	get->test[4] = "";
// // }

void	finish_list_with(char **list, char *put)
{
	char	*temp;

	while (*list)
	{
		temp = ft_strjoin(*list, put);
		free(*list);
		*list = temp;
		list++;
	}
}

int	get_paths(char **envp, t_control *get)
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

// void	run_input(t_control *get)
// {
// 	(void)get;
// }

char	*build_command(t_control *get, char *command)
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
	return (ft_strjoin(get->paths[--i], command));
}

// void	structure_commands(t_control *get)
// {
// 	int	i;

// 	while (get->argv[i])
// 	{

// 	}
// }


void	printf_input(t_control *get)
{
	ft_printf("\nInput-->\n");
	for (int i = 0; get->pieces[i]; i++)
	{
		ft_printf("command %i->\n", i);
		for (int j = 0; get->pieces[i][j]; j++)
			ft_printf("%s\n", get->pieces[i][j]);
	}
	ft_printf("end.\n");
}

int	main(int argc, char **argv, char **envp)
{
	static t_control	get;

	(void)argv;
	(void)argc;
	// setup structures and variables.
	setup(&get, envp);
	while (true)
	{
		get.input = get_next_line(0);
		normalize_input(&get);
		// structure_commands(&get);
		printf_input(&get);
		free_shellsplit(get.pieces);
		free(get.input);
		// run_input(&get);
	}
	return (1);
}
