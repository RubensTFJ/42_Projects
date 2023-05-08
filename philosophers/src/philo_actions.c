/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:46:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/08 23:26:47 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	att_turn(t_control *get)
{
	static int	eat;

	if (++eat >= (get->total / 2))
	{
		eat = 0;
		if (get->turn + 1 > get->total)
			get->turn = 1;
		else
			get->turn++;
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->status != THINKING)
	{
		ft_message(THINKING, philo);
		philo->status = THINKING;
	}
}

void	philo_sleep(t_philo *philo)
{
	t_ulong	start;

	ft_message(SLEEPING, philo);
	philo->status = SLEEPING;
	start = get_time();
	while ((get_time() - start) < philo->table->sleep_timer
		&& philo->alive(philo))
		;
}

void	philo_eat(t_philo *philo)
{
	take_fork(philo->table->utensils[philo->id], philo);
	take_fork(philo->table->utensils[philo->id - 1], philo);
	ft_message(EATING, philo);
	att_turn(philo->table);
	usleep(1000 * philo->table->eat_timer);
	philo->last_eat = get_time();
	philo->eat_times++;
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
