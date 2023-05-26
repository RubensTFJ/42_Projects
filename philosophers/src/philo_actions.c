/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:46:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 23:36:01 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	att_turn(t_control *get)
{
	static int	eat;

	pthread_mutex_lock(&get->turn_lock);
	if (++eat >= (get->total / 2))
	{
		eat = 0;
		if (get->turn + 1 > get->total)
			get->turn = 1;
		else
			get->turn++;
	}
	pthread_mutex_unlock(&get->turn_lock);
}

void	philo_think(t_philo *philo)
{
	if (philo->status != THINKING)
	{
		ft_message(THINKING, philo);
		philo->status = THINKING;
	}
	usleep(150);
}

void	philo_sleep(t_philo *philo)
{
	ft_message(SLEEPING, philo);
	philo->status = SLEEPING;
	watch_sleep(philo->table->sleep_timer, philo);
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo->table->utensils[philo->id], philo);
	take_fork(philo->table->utensils[philo->id - 1], philo);
	ft_message(EATING, philo);
	philo->last_eat = get_time();
	philo->eat_times++;
	att_turn(philo->table);
	watch_sleep(philo->table->eat_timer, philo);
	release_fork(philo->table->utensils[philo->id]);
	release_fork(philo->table->utensils[philo->id - 1]);
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
