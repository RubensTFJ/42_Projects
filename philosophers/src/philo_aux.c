/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 20:03:32 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	wait_next_turn(t_philo *philo)
{
	while (philo->wait == philo->info->turn)
	{
		if (!philo->alive)
			philo->death(philo);
	}
}

t_philo	*new_philosopher(t_control *get, int id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->id = id;
	philo->status = 3;
	philo->turn = is_turn;
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
	}
	return (1);
}

void	message(int type, t_philo *philo)
{
	(void)type;
	(void)philo;
}
