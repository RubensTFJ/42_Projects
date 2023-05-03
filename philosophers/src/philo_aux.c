/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 21:53:34 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	wait_next_turn(t_philo *philo)
{
	while (philo->wait == philo->info->turn)
	{
		if (!philo->alive)
			;
			// philo->death(philo);
	}
}

t_philo	*new_philosopher(t_control *get, int id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->id = id;
	philo->status = 3;
	philo->turn = is_turn;
	philo->eat = philo_eat;
	philo->think = philo_think;
	philo->sleep = philo_sleep;
	philo->alive = is_philo_alive;
	philo->info = get;
	return (philo);
}

int	forks_down(t_control *get)
{
	int	i;

	i = 0;
	while (i < get->total)
	{
		if (!get->forks[i])
			return (0);
		i++;
	}
	return (1);
}

int	message(int type, t_philo *philo)
{
	if (type == DEAD)
		return (printf("turn: %i, time: %li: Philosopher: %i Died.\n", philo->info->turn, get_time(), philo->id));
	if (type == EATING)
		return (printf("turn: %i, time: %li: Philosopher: %i Started Eating.\n",philo->info->turn, get_time(), philo->id));
	if (type == SLEEPING)
		return (printf("turn: %i, time: %li: Philosopher: %i Is Sleeping.\n",philo->info->turn, get_time(), philo->id));
	if (type == THINKING)
		return (printf("turn: %i, time: %li: Philosopher: %i Is Thinking.\n",philo->info->turn, get_time(), philo->id));
	if (type == TAKE_FORK)
		return (printf("turn: %i, time: %li: Philosopher: %i Took a Fork.\n",philo->info->turn, get_time(), philo->id));
	return (0);	
}
