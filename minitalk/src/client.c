/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:11:41 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/28 22:39:16 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	ft_talk_message(unsigned char *message, int PID, int bytes);
void		ft_recieve_signal(int signal);

int	main(int counter, char **input)
{
	int					process_id;
	int					length;
	struct sigaction	info;

	if (counter != 3)
	{
		ft_printf("Usage: ./client <PID> <message>");
		return (1);
	}
	info.sa_sigaction = (void *)ft_recieve_signal;
	info.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &info, 0);
	sigaction(SIGUSR2, &info, 0);
	process_id = ft_atoi(input[1]);
	length = ft_strlen(input[2]);
	ft_talk_message((unsigned char *)(&length), process_id, 4);
	ft_talk_message((unsigned char *)input[2], process_id, length);
	return (0);
}

void	ft_recieve_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sent.\n");
}

static void	ft_talk_message(unsigned char *message, int process_id, int bytes)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < bytes)
	{
		pos = -1;
		while (++pos < 8)
		{
			if (message[i] & (1 << pos))
				kill(process_id, SIGUSR2);
			else
				kill(process_id, SIGUSR1);
			usleep(500000);
		}
	}
}
