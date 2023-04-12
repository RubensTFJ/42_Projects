/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:11:41 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/12 20:41:46 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	ft_talk_message(unsigned char *message, int PID, int bytes)
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
				kill(PID, SIGUSR2);
			else
				kill(PID, SIGUSR1);
			usleep(50);
		}
	}
}

int main(int counter, char **input)
{
	int	PID;
	int length;
	
	if (counter != 3)
	{
		ft_printf("Usage: ./client <PID> <message>");
		return (1);
	}
	PID = ft_atoi(input[1]);
	length = ft_strlen(input[2]);
	ft_talk_message((unsigned char *)(&length), PID, 4);
	ft_talk_message((unsigned char *)input[2], PID, length);
	return (0);
}