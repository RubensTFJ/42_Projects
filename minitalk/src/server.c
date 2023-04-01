/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 23:36:13 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/01 00:25:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	signal_handler(int signal)
{
	(void)signal;
	ft_printf("Signal recieved\n");
}

int	main(int counter, char **input)
{
	int	process_id;

	(void)input;
	if (counter != 1)
		ft_printf("Usage: ./server\n");
	process_id = getpid();
	ft_printf("PID -> %i.\n", process_id);	
	while (LOOP)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}

// void sigint_handler(int signal)
// {
// 	(void)signal;
//     printf("Received SIGINT signal\n");
// }

// int main()
// {
//     // Register the signal handler function for SIGINT
//     signal(SIGINT, sigint_handler);

//     // Do some work here...
//     while(1) {}

//     return 0;
// }