/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/02 22:03:53 by rteles-f         ###   ########.fr       */
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

// void	move_fork(t_philo *from, t_philo *to)
// {
// 	if (!from || !to || !from->fork)
// 		return ;
// 	to->borrow = from->fork;
// 	from->fork->holder = to;
// 	from->fork = NULL;
// }

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_philo	*set_philosopher(t_control *get, int id)
{
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), 1);
	philo->id = id;
	philo->status = 3;
	philo->turn = is_turn;
	philo->think = philo_think;
	philo->sleep = philo_sleep;
	philo->info = get;
	return (philo);
}

void	philo_eat(t_philo *philo)
{
	philo->right = philo->info->forks[philo->id];
	pthread_mutex_lock(philo->info->forks[philo->id]);
	message(TAKE_FORK, philo);
	philo->left = philo->info->forks[philo->id - 1];
	pthread_mutex_lock(philo->info->forks[philo->id - 1]);
	message(TAKE_FORK, philo);
	message(EATING, philo);
	wait(philo->info->eat_timer);
	philo->last_eat = get_time();
}

void	create_philosophers(t_control *get, char **input)
{
	t_philo	philo;
	int		i;

	philo.info = get;
	get->total = ft_atoi(input[0]);
	get->death_timer = ft_atoi(input[1]);
	get->eat_timer = ft_atoi(input[2]);
	get->sleep_timer = ft_atoi(input[3]);
	get->last_meal = ft_atoi(input[4]);
	get->forks = ft_calloc(sizeof(int *), get->total + 1);
	i = 0;
	while (i < get->total)
	{
		get->forks[i] = ft_calloc(sizeof(int), 1);
		*get->forks[i] = 1;
		i++;
	}
	get->forks[get->total] = get->forks[0];
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

void	*maitre(void *arg)
{
	t_control	*get;

	get = (t_control *)arg;
	while (get->total)
	{
		while (!forks_down(get))
			;
		get->turn++;
		if (get->turn > get->total)
			get->turn = 1;
		while (forks_down(get))
			;
	}
}

void	*decorum(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->status != DEAD)
	{
		if (philo->turn(philo))
		{
			philo->eat(philo);
			philo->sleep(philo);
		}
		else
			philo->think(philo);
	}
	philo->death(philo);
}

int	main(int counter, char **input)
{
	t_control		get;

	pthread_create(,   (void *)(&get));
	if (counter < 4)
		return ;
	create_philosophers(&get, input);
}
