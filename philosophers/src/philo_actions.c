/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:46:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 20:02:53 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_eat(t_philo *philo)
{
	take_fork(philo->info->forks[philo->id], philo);
	take_fork(philo->info->forks[philo->id - 1], philo);
	message(EATING, philo);
	sleep(philo->info->eat_timer);
	philo->last_eat = get_time();
	philo->eat_times++;
	release_fork(philo->info->forks[philo->id]);
	release_fork(philo->info->forks[philo->id - 1]);
}

void	philo_think(t_philo *philo)
{
	message(THINKING, philo);
	wait_next_turn(philo);
}

void	philo_sleep(t_philo *philo)
{
	message(SLEEPING, philo);
	sleep(philo->info->sleep_timer);
	wait_next_turn(philo);
}

void	*decorum(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->alive(philo))
	{
		if (philo->turn(philo))
		{
			philo->eat(philo);
			philo->sleep(philo);
		}
		else
			philo->think(philo);
	}
	return (arg);
}
