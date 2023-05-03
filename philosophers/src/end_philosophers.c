/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:35:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 20:02:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	free_biarray(void **arg)
{
	int		**temp;
	int		i;

	if (!arg)
		return ;
	temp = ((int **)arg);
	i = 0;
	while (temp[i])
		free(temp[i++]);
	free(arg);
}

void	destroy_mutex(t_fork **forks)
{
	int	i;

	i = 0;
	while (forks[i])
		pthread_mutex_destroy(&forks[i]->lock);
}

void	end_dinner(char *string, t_control *get)
{
	if (string)
		ft_printf("%s", string);
	if (get->philosophers)
		free_biarray((void **)get->philosophers);
	if (get->forks)
	{
		destroy_mutex(get->forks);
		free_biarray((void **)get->forks);
	}
}
