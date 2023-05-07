/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:07:12 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/05 16:36:24 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	thread_joiner(t_control *get)
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
	{
		end_dinner("Failed to Allocate Memory.\n", get);
		return (0);
	}
	i = 0;
	while (i < get->total)
	{
		get->philosophers[i] = new_philosopher(get, (i + 1));
		if (pthread_create(&get->philosophers[i]->thread, NULL,
				table_manners, get->philosophers[i]) != 0)
		{
			end_dinner("Failed to Create Thread.\n", get);
			return (0);
		}
		i++;
	}
	return (1);
}

int	serve_utensils(t_control *get)
{
	int	i;

	get->utensils = ft_calloc(sizeof(t_fork *), get->total + 1);
	if (!get->utensils)
	{
		end_dinner("Failed to Allocate Memory.\n", get);
		return (0);
	}
	i = 0;
	while (i < get->total)
	{
		get->utensils[i] = ft_calloc(sizeof(t_fork), 1);
		get->utensils[i]->fork = 1;
		if (pthread_mutex_init(&get->utensils[i]->lock, NULL) != 0)
		{
			end_dinner("Failed to Init Mutex\n", get);
			return (0);
		}
		i++;
	}
	get->utensils[get->total] = get->utensils[0];
	return (1);
}

int	check_start(t_control *get, int counter, char **input)
{
	if (counter < 5 || counter > 6)
	{
		end_dinner("Wrong Usage.\n", get);
		return (0);
	}
	get->total = ft_atoi(input[1]);
	get->death_timer = ft_atoi(input[2]);
	get->eat_timer = ft_atoi(input[3]);
	get->sleep_timer = ft_atoi(input[4]);
	get->clock = get_time();
	get->turn = 1;
	get->service = 1;
	if (input[5])
		get->last_meal = ft_atoi(input[5]);
	else
		get->last_meal = -1;
	return (1);
}

int	main(int counter, char **input)
{
	static t_control	get;

	if (!check_start(&get, counter, input) || \
		!serve_utensils(&get) || \
		!put_philosophers_on_table(&get))
		return (1);
	thread_joiner(&get);
	end_dinner("", &get);
	return (0);
}
	// start_dinner(&get);

// void	*start_dinner(void *arg)
// {
// 	t_control	*get;

// 	get = (t_control *)arg;
// 	while (get->total)
// 	{
// 		// !utensils_down(get) && 
// 		// while (get->all_utensils != get->total)
// 		// 	;
// 		// if ((get->turn + 1) > get->total)
// 		// 	get->turn = 1;
// 		// else
// 		// 	get->turn++;
// 		// while (get->all_utensils == get->total)
// 		// 	;
// 	}
// 	// HERE;
// 	return (arg);
// }