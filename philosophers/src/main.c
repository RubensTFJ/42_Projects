/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/04/29 02:41:14 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

// void	read_status()
// {
// 	if (status == 0)
// 		death;
// 	else if (status == 1)
// 		took fork;
// 		eating;
// 	else if (status == 2)
// 		sleeping;
// 	else if (status == 3)
// 		thinking;
// }

// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

void	move_fork(t_philo *from, t_philo *to)
{
	if (!from || !to || !from->fork)
		return ;
	to->borrow = from->fork;
	from->fork->holder = to;
	from->fork = NULL;
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	set_philosopher(int	id)
{
	t_philo *philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->fork = ft_calloc(sizeof(t_fork), 1);
	philo->fork->owner = philo;
	philo->id = id;
	philo->status = 3;
}

void	create_philosophers(t_control *get, char **input)
{
	int		i;
	t_philo	*philo;

	get->total = ft_atoi(input[0]);
	get->death_timer = ft_atoi(input[1]);
	get->eat_timer = ft_atoi(input[2]);
	get->sleep_timer = ft_atoi(input[3]);
	get->last_meal = ft_atoi(input[4]);
	while (i < get->total)
		philo = ft_calloc(sizeof(t_philo), 1);
	
}

int	main(int counter, char **input)
{
	t_control	get;

	if (counter < 4)
		return ;
	create_philosophers(&get, input);
}