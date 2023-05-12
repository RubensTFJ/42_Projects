/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:43:59 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/13 00:04:09 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_unsplit(char **split, int posize)
{
	char	*line;
	int		i;

	if (*split)
		line = ft_unsplit((split + 1), posize + ft_strlen(*split) + 1);
	else
		return (ft_calloc(sizeof(char), posize + 1));
	i = 0;
	while ((*split)[i])
		line[posize++] = (*split)[i++];
	line[posize] = ' ';
	return (line);
}

int	prepare_input(t_control *get)
{
	get->line = ft_unsplit(get->argv, 0);
	ft_printf("%s\n", get->line);
	free(get->line);
	return (1);
}

void	space_case();
void	pipe_case();
void	amper_case();
void	semi_colon_case();
void	redirection_case();

void	input_parse(t_control *get)
{
	int	i;
	int	j;

	while (get->line[i])
	{
		j = 0;
		while (get->find[j] && !ft_strncmp(get->line[i], get->find[j]))
			j++;
		if (!ft_strncmp(get->line[i], get->find[j]))
			get->functions[j](get, &i);
		i++;
	}
}

void	set_functions(t_control *get)
{
	get->functions[0] = space_case;
	get->functions[1] = pipe_case;
	get->functions[2] = amper_case;
	get->functions[3] = semi_colon_case;
	get->functions[4] = redirection_case;
	get->functions[5] = redirection_case;
	get->find[0] = ' ';
	get->find[1] = '|';
	get->find[2] = '&';
	get->find[3] = '/';
	get->find[4] = '<';
	get->find[5] = '>';
	get->find[6] = '0';
	get->test[0] = "wc";
	get->test[1] = "ls";
	get->test[2] = "cat";
	get->test[3] = "";
	get->test[4] = "";
}

int	check_input(t_control *get, int argc, char **argv, char **envp)
{
	get->argc = argc;
	get->argv = argv;
	get->envp = envp;
	set_functions(get);
	prepare_input(get);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	static t_control	get;
	
	check_input(&get, argc, argv, envp);
	return (1);
}
