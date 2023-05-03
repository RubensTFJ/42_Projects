/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:39:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 20:04:15 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

t_ulong	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	is_philo_alive(t_philo *philo)
{
	if ((get_time() - philo->last_eat) > philo->info->death_timer)
		return (0);
	return (1);
}

void	release_fork(t_fork *get)
{
	get->fork = 1;
	pthread_mutex_unlock(&get->lock);
}

void	take_fork(t_fork *get, t_philo *philo)
{
	pthread_mutex_lock(&get->lock);
	message(TAKE_FORK, philo);
	get->fork = 0;
}

int	is_turn(t_philo *philo)
{
	int	total;
	int	id;
	int	turn;

	total = philo->info->total;
	id = philo->id;
	turn = philo->info->turn;
	if (!(total % 2))
		turn = (turn % 2);
	if ((id % 2) == (turn % 2) && id >= turn)
	{
		if (turn == 1 && id == total)
			return (0);
		return (1);
	}
	else if ((id % 2) != (turn % 2) && (id + 1) < turn)
		return (1);
	return (0);
}
