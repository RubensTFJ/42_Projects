/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:43:59 by rteles-f          #+#    #+#             */
/*   Updated: 2023/06/05 19:25:47 by rteles-f         ###   ########.fr       */
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
	setup(&get, envp);
	while (true)
	{
		get.input = get_next_line(0);
		normalize_input(&get);
		structure_commands(&get);
		run_input(get.commands);
		// clear_commands(&get);
	}
	return (1);
}
