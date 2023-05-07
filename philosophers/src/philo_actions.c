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

void	att_turn(t_control *get)
{
	static int	eat;

	usleep(100);
	if (++eat == (get->total / 2))
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
	ft_message(SLEEPING, philo);
	philo->status = SLEEPING;
	ft_usleep(philo, philo->table->sleep_timer);
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
