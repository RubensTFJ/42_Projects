/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pactions_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:43 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	take_fork(t_fork *get, t_philo *philo)
{
	pthread_mutex_lock(&get->lock);
	ft_message(TAKE_FORK, philo);
	get->fork = 0;
}

void	release_fork(t_fork *get)
{
	get->fork = 1;
	pthread_mutex_unlock(&get->lock);
}

int	ft_message(int type, t_philo *philo)
{
	if (!philo->table->service)
		return (0);
	if (type == DEAD)
		return (printf("((Turn: %i)) %li: Philosopher: %i Died.\n",
				philo->table->turn, get_time() - philo->table->watch, philo->id));
	if (type == EATING)
		return (printf("%li %i is eating.\n",
				get_time() - philo->table->watch, philo->id));
	if (type == SLEEPING)
		return (printf("%li %i is sleeping.\n",
				get_time() - philo->table->watch, philo->id));
	if (type == THINKING)
		return (printf("%li %i is thinking.\n",
				get_time() - philo->table->watch, philo->id));
	if (type == TAKE_FORK)
		return (printf("%li %i has taken a Fork.\n",
				get_time() - philo->table->watch, philo->id));
	return (0);
}

int	is_philo_alive(t_philo *philo)
{
	if (!philo->status || !philo->table->service)
		return (0);
	if ((get_time() - philo->last_eat) > philo->table->death_timer)
	{
		ft_message(DEAD, philo);
		philo->table->service = 0;
		philo->status = 0;
		return (0);
	}
	return (1);
}

int	is_turn(t_philo *philo)
{
	int			total;
	int			id;
	int			turn;

	total = philo->table->total;
	id = philo->id;
	turn = philo->table->turn;
	if (!(total % 2))
		turn = (turn % 2);
	if ((id % 2) == (turn % 2) && id >= turn)
	{
		if (turn == 1 && philo->id == philo->table->total)
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