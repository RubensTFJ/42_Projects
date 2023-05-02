/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:46:03 by rteles-f          #+#    #+#             */
/*   Updated: 2023/05/02 20:46:17 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

void	philo_think(t_philo *philo)
{
	message(THINKING, philo->id);
	wait_next_turn(philo->info->turn);
}

void	philo_sleep(t_philo *philo)
{
	message(SLEEPING, philo->id);
	wait_next_turn(philo->info->turn);
}