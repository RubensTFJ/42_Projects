/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:23:10 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/28 20:08:59 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	**ft_here_doc(char *string, char *end, int pos)
{
	char	**input_doc;

	input_doc = NULL;
	if (!ft_strncmp(string, end, ft_strlen(end))
		&& (string[ft_strlen(end)] == '\n'))
	{
		input_doc = ft_calloc(sizeof(char *), (pos + 2));
		free(string);
	}
	else
	{
		ft_printf("pipe heredoc> ");
		input_doc = ft_here_doc(get_next_line(0), end, (pos + 1));
		input_doc[pos] = string;
	}
	return (input_doc);
}

void	ft_init_here_doc(char *end, t_vars *get, char *outfile)
{
	char	**input;
	int		i;

	ft_printf("pipe heredoc> ");
	input = ft_here_doc(get_next_line(0), end, 0);
	pipe(get->pipe);
	i = 0;
	while (input[i])
	{
		write(get->pipe[1], input[i], ft_strlen(input[i]));
		free(input[i]);
		i++;
	}
	close(get->pipe[1]);
	free(input);
	get->fd[0] = get->pipe[0];
	get->fd[1] = open(outfile, O_APPEND | O_CREAT | O_WRONLY, 0000644);
	if (get->fd[1] < 0)
		end_pipex(get, 3, "Failed to Open Outfile.");
}
