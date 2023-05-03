/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/03 21:54:09 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	*start_dinner(void *arg)
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
		printf("turno: %i\n", get->turn);
	}
	return (arg);
}

void	serve_forks(t_control *get)
{
	int	i;

	get->forks = ft_calloc(sizeof(t_fork *), get->total + 1);
	i = 0;
	while (i < get->total)
	{
		get->forks[i] = ft_calloc(sizeof(t_fork), 1);
		get->forks[i]->fork = 1;
		if (pthread_mutex_init(&get->forks[i]->lock, NULL) != 0)
			end_dinner("Failed to Init Mutex\n", get);
		i++;
	}
	get->forks[get->total] = get->forks[0];
}

void	put_philosophers_on_table(t_control *get)
{
	int	i;

	get->philosophers = ft_calloc(sizeof(t_control *), get->total);
	i = 0;
	while (i < get->total)
	{
		get->philosophers[i] = new_philosopher(get, (i + 1));
		if (pthread_create(&get->philosophers[i]->thread, NULL,
			decorum, get->philosophers[i]) != 0)
		{

			end_dinner("Failed to Create Thread.\n", get);
		}
		i++;
	}
	// i = 0;
	// while (get->philosophers[i])
	// {
	// 	pthread_join(get->philosophers[i]->thread, NULL);
	// 		DEBUG2;
	// 	i++;
	// }
}

void	check_start(t_control *get, int counter, char **input)
{
	if (counter < 4 || counter > 6)
		end_dinner("Wrong Usage.\n", get);
	get->total = ft_atoi(input[1]);
	get->death_timer = ft_atoi(input[2]);
	get->eat_timer = ft_atoi(input[3]);
	get->sleep_timer = ft_atoi(input[4]);
	if (input[5])
		get->last_meal = ft_atoi(input[5]);
}

int	main(int counter, char **input)
{
	static t_control	get;

	check_start(&get, counter, input);
	put_philosophers_on_table(&get);
	serve_forks(&get);
	start_dinner(&get);
	end_dinner("", &get);
	return (0);
}
