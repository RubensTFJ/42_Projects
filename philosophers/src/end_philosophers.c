/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:35:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/26 23:03:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	free_biarray(void **arg, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(arg[i++]);
	free(arg);
}

void	destroy_mutex(t_fork **utensils, int size)
{
	int	i;

	i = 0;
	while (i < size)
		pthread_mutex_destroy(&utensils[i++]->lock);
}

int	end_dinner(char *string, t_control *get)
{
	if (string)
		printf("%s", string);
	if (get->philosophers)
		free_biarray((void **)get->philosophers, get->total);
	if (get->utensils)
	{
		destroy_mutex(get->utensils, get->total);
		pthread_mutex_destroy(&get->turn_lock);
		pthread_mutex_destroy(&get->service_lock);
		free_biarray((void **)get->utensils, get->total);
	}
	return (0);
}

t_ulong	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_philo	*new_philosopher(t_control *get, int id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->id = id;
	philo->status = 1;
	philo->last_eat = get_time();
	philo->turn = is_turn;
	philo->eat = philo_eat;
	philo->think = philo_think;
	philo->sleep = philo_sleep;
	philo->alive = check_table;
	philo->table = get;
	return (philo);
}
