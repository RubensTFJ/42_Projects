/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:39:19 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/04 19:08:26 by rteles-f         ###   ########.fr       */
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
	// printf("philo: %i, time: %li\n", philo->id, (get_time() - philo->last_eat));
	// if (!(philo->id % 2))
	// {
	// 	printf("id: %i, status: %i\n",philo->id, philo->status);
	// }
	if (!philo->status)
		return (0);
	if ((get_time() - philo->last_eat) > philo->info->death_timer
		|| !philo->info->total)
	{
		message(DEAD, philo);
		philo->status = 0;
		philo->info->total = 0;
		return (0);
	}
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
	philo->wait = philo->info->turn;
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

// int main(void)
// {
// 	int	i;
// 	int	j;
// 	t_philo philo;
// 	t_control get;

// 	philo.info = &get;
// 	philo.info->turn = 1;
// 	philo.info->total = 5;
// 	i = 1;
// 	while (i <= philo.info->total)
// 	{
// 		philo.info->turn = i;
// 		j = 1;
// 		printf("turn: %i\n",i);
// 		while (j <= philo.info->total)
// 		{
// 			philo.id = j;
// 			if (is_turn(&philo))
// 				printf("%i, ", j);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// }