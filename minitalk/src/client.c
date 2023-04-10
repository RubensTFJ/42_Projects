/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:11:41 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/10 22:09:47 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int main(int counter, char **input)
{
	int	process_id;

	if (counter != 3)
	{
		ft_printf("Usage: ./server *message");
		return (1);
	}
	process_id = ft_atoi(input[1]);
	ft_printf("%i\n");
	return (0);
}