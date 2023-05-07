/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:46:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 19:47:12 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	ft_usleep(t_philo *philo, t_ulong time)
{
	t_ulong	start;

	start = get_time();
	while ((get_time() - start) < time && philo->alive(philo))
		;
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo->table->forks[philo->id], philo);
	take_fork(philo->table->forks[philo->id - 1], philo);
	ft_message(EATING, philo);
	philo->status = EATING;
	usleep(1000 * philo->table->eat_timer);
	philo->last_eat = get_time();
	philo->eat_times++;
	release_fork(philo->table->forks[philo->id]);
	release_fork(philo->table->forks[philo->id - 1]);
}

void	philo_think(t_philo *philo)
{
	if (philo->status != THINKING)
	{
		ft_message(THINKING, philo);
		philo->status = THINKING;
	}
	usleep(100);
}

void	philo_sleep(t_philo *philo)
{
	ft_message(SLEEPING, philo);
	philo->status = SLEEPING;
	ft_usleep(philo, philo->table->sleep_timer);
}

void	*table_manners(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = get_time();
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
