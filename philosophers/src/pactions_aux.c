/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pactions_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 23:38:26 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	check_table(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->service_lock);
	if (!philo->status || !philo->table->service)
		return (pthread_mutex_unlock(&philo->table->service_lock) * 0);
	if ((get_time() - philo->last_eat) > philo->table->death_timer)
	{
		ft_message(DEAD, philo);
		philo->table->service = 0;
		philo->status = 0;
		return (pthread_mutex_unlock(&philo->table->service_lock) * 0);
	}
	if (philo->eat_times == philo->table->last_meal)
	{
		philo->table->service = 0;
		return (pthread_mutex_unlock(&philo->table->service_lock) * 0);
	}
	pthread_mutex_unlock(&philo->table->service_lock);
	return (1);
}

int	is_turn(t_philo *philo)
{
	int			total;
	int			id;
	int			turn;

	pthread_mutex_lock(&philo->table->turn_lock);
	total = philo->table->total;
	id = philo->id;
	turn = philo->table->turn;
	if (!(total % 2))
		turn = (turn % 2);
	if ((id % 2) == (turn % 2) && id >= turn
		&& !(turn == 1 && philo->id == philo->table->total))
		return (pthread_mutex_unlock(&philo->table->turn_lock) * 0 + 1);
	else if ((id % 2) != (turn % 2) && (id + 1) < turn)
		return (pthread_mutex_unlock(&philo->table->turn_lock) * 0 + 1);
	return (pthread_mutex_unlock(&philo->table->turn_lock) * 0);
}

void	take_fork(t_fork *get, t_philo *philo)
{
	int	go;

	go = 1;
	while (go)
	{
		pthread_mutex_lock(&get->lock);
		if (get->fork)
		{
			get->fork = 0;
			go = 0;
			ft_message(TAKE_FORK, philo);
			pthread_mutex_unlock(&get->lock);
		}
		else
		{
			pthread_mutex_unlock(&get->lock);
			philo->alive(philo);
			philo->think(philo);
		}
	}
}

void	release_fork(t_fork *get)
{
	pthread_mutex_lock(&get->lock);
	get->fork = 1;
	pthread_mutex_unlock(&get->lock);
}

int	ft_message(int type, t_philo *philo)
{
	if (type == DEAD)
		return (printf("%.05li %i Died.\n",
				get_time() - philo->table->clock, philo->id));
	pthread_mutex_lock(&philo->table->service_lock);
	if (!philo->table->service)
		return (pthread_mutex_unlock(&philo->table->service_lock) * 0);
	pthread_mutex_unlock(&philo->table->service_lock);
	if (type == EATING)
		return (printf("%.05li %i is eating.\n",
				get_time() - philo->table->clock, philo->id));
	if (type == SLEEPING)
		return (printf("%.05li %i is sleeping.\n",
				get_time() - philo->table->clock, philo->id));
	if (type == THINKING)
		return (printf("%.05li %i is thinking.\n",
				get_time() - philo->table->clock, philo->id));
	if (type == TAKE_FORK)
		return (printf("%.05li %i has taken a Fork.\n",
				get_time() - philo->table->clock, philo->id));
	return (0);
}
// int main(void)
// {
// 	int	i;
// 	int	j;
// 	t_philo philo;
// 	t_control get;

// 	philo.table = &get;
// 	philo.table->turn = 1;
// 	philo.table->total = 5;
// 	i = 1;
// 	while (i <= philo.table->total)
// 	{
// 		philo.table->turn = i;
// 		j = 1;
// 		printf("turn: %i\n",i);
// 		while (j <= philo.table->total)
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