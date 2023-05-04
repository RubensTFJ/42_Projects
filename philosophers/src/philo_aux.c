/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:45 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/04 19:26:28 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	wait_next_turn(t_philo *philo)
{
	// printf("wait: %i, turn :%i\n", philo->wait, philo->info->turn);
	while (philo->wait == philo->info->turn || philo->info->turn == 1)
	{
		// if (!(philo->id % 2))
		// 	DEBUG1;
		if ((philo->wait == philo->info->total || philo->wait == philo->info->total - 1)
			&& philo->info->turn == 1)
		{
			philo->wait = philo->info->turn;
			return ;
		}
		if (!philo->alive(philo))
			return ;
	}
}

t_philo	*new_philosopher(t_control *get, int id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->id = id;
	philo->wait = 1;
	philo->status = 3;
	philo->last_eat = get_time();
	philo->turn = is_turn;
	philo->eat = philo_eat;
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
		if (!get->forks[i]->fork)
			return (0);
		i++;
	}
	return (1);
}

int	message(int type, t_philo *philo)
{
	if (type == DEAD)
		return (printf(" XXX  turn: %i, wait: %i: Philosopher: %i Died.\n", philo->info->turn, philo->wait, philo->id));
	if (type == EATING)
		return (printf("turn: %i, wait: %i: Philosopher: %i Started Eating.\n",philo->info->turn, philo->wait, philo->id));
	if (type == SLEEPING)
		return (printf("turn: %i, wait: %i: Philosopher: %i Is Sleeping.\n",philo->info->turn, philo->wait, philo->id));
	if (type == THINKING)
		return (printf("turn: %i, wait: %i: Philosopher: %i Is Thinking.\n",philo->info->turn, philo->wait, philo->id));
	if (type == TAKE_FORK)
		return (printf("turn: %i, wait: %i: Philosopher: %i Took a Fork.\n",philo->info->turn, philo->wait, philo->id));
	return (0);	
}
