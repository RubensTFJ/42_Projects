/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:36:13 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/12 20:52:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	ft_build_message(t_talk *get)
{
	static int	pos;

	get->string[pos++] = get->bit;
	get->sent++;
	if (get->sent == get->size)
	{
		get->bit = 0;
		get->size = 0;
		get->sent = 0;
		pos = 0;
		ft_printf("%s\n", get->string);
		free(get->string);
		get->string = NULL;
	}
}

static int	ft_build_package(int signal, int limit)
{
	static int	pos;
	static int	variable;
	int			result;

	if (signal == SIGUSR2)
		variable |= (1 << pos);
	pos++;
	if (pos == limit)
	{
		result = variable;
		pos = 0;
		variable = 0;
		return (result);
	}
	return (0);
}

static void	ft_signal_handler(int signal)
{
	static t_talk	get;

	if (!get.size)
	{
		get.size = ft_build_package(signal, 32);
		if (get.size)
			get.string = ft_calloc(sizeof(char), get.size + 1);
	}
	else
	{
		get.bit = (char)ft_build_package(signal, 8);
		if (get.bit)
			ft_build_message(&get);
	}
}

int	main(int counter, char **input)
{
	(void)input;
	if (counter != 1)
		ft_printf("Usage: ./server\n");
	ft_printf("PID -> %i\n", getpid());
	signal(SIGUSR1, ft_signal_handler);
	signal(SIGUSR2, ft_signal_handler);
	while (true)
		pause();
	return (0);
}
