/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/22 16:39:05 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	wait_dinner(t_control *get)
{
	int	i;

	i = 0;
	while (i < get->total)
	{
		pthread_join(get->philosophers[i]->thread, NULL);
		i++;
	}
}

int	put_philosophers_on_table(t_control *get)
{
	int	i;

	get->philosophers = ft_calloc(sizeof(t_control *), get->total);
	if (!get->philosophers)
		return (end_dinner("Failed to Allocate Memory.\n", get));
	i = 0;
	while (i < get->total)
	{
		get->philosophers[i] = new_philosopher(get, (i + 1));
		if (pthread_create(&get->philosophers[i]->thread, NULL,
				table_manners, get->philosophers[i]) != 0)
			return (end_dinner("Failed to Create Thread.\n", get));
		i++;
	}
	return (1);
}

int	serve_utensils(t_control *get)
{
	int	i;

	get->utensils = ft_calloc(sizeof(t_fork *), get->total + 1);
	if (!get->utensils)
		return (end_dinner("Failed to Allocate Memory.\n", get));
	i = 0;
	while (i < get->total)
	{
		get->utensils[i] = ft_calloc(sizeof(t_fork), 1);
		get->utensils[i]->fork = 1;
		if (pthread_mutex_init(&get->utensils[i]->lock, NULL) != 0)
			return (end_dinner("Failed to Init Mutex\n", get));
		i++;
	}
	get->utensils[get->total] = get->utensils[0];
	return (1);
}

int	check_start(t_control *get, int counter, char **input)
{
	if (counter < 5 || counter > 6)
		return (end_dinner("Wrong Usage.\n", get));
	get->total = ft_atoi(input[1]);
	get->death_timer = ft_atoi(input[2]);
	get->eat_timer = ft_atoi(input[3]);
	get->sleep_timer = ft_atoi(input[4]);
	if (input[5])
		get->last_meal = ft_atoi(input[5]);
	if ((int)get->eat_timer < 0 || (int)get->total < 0 || get->last_meal < 0
		|| (int)get->sleep_timer < 0 || (int)get->death_timer < 0)
		return (end_dinner("Input Can't be negative.\n", get));
	if (!input[5])
		get->last_meal = -1;
	get->clock = get_time();
	get->turn = 1;
	get->service = 1;
	pthread_mutex_init(&get->turn_lock, NULL);
	pthread_mutex_init(&get->service_lock, NULL);
	return (1);
}

int	main(int counter, char **input)
{
	static t_control	get;

	if (!check_start(&get, counter, input) || \
		!serve_utensils(&get) || \
		!put_philosophers_on_table(&get))
		return (1);
	wait_dinner(&get);
	end_dinner("", &get);
	return (0);
}
